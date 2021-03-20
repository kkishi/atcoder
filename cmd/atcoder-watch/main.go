package main

import (
	"encoding/json"
	"errors"
	"fmt"
	"html"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"net/http/cookiejar"
	"net/url"
	"os"
	"os/user"
	"path/filepath"
	"regexp"
	"strconv"
	"strings"
	"text/tabwriter"
	"time"

	"golang.org/x/net/publicsuffix"

	aurora "github.com/logrusorgru/aurora/v3"
)

func newClient() (*http.Client, error) {
	u, err := url.Parse("https://atcoder.jp/")
	if err != nil {
		return nil, err
	}
	jar, err := cookiejar.New(&cookiejar.Options{PublicSuffixList: publicsuffix.List})
	if err != nil {
		return nil, err
	}
	// HACK: Reuse the cookiejar for oj.
	usr, err := user.Current()
	if err != nil {
		return nil, err
	}
	b, err := ioutil.ReadFile(filepath.Join(usr.HomeDir, ".local/share/online-judge-tools/cookie.jar"))
	if err != nil {
		return nil, err
	}
	m := regexp.MustCompile(`REVEL_SESSION="([^"]+)"`).FindStringSubmatch(string(b))
	if len(m) != 2 {
		return nil, errors.New("REVEL_SESSION not found")
	}
	jar.SetCookies(u, []*http.Cookie{
		{
			Name:   "REVEL_SESSION",
			Value:  m[1],
			Path:   "/",
			Domain: "atcoder.jp",
		},
	})
	return &http.Client{
		Jar: jar,
		CheckRedirect: func(req *http.Request, via []*http.Request) error {
			return fmt.Errorf("request for %s got redirected to %s, check if you are logged in",
				via[len(via)-1].URL, req.URL)
		},
	}, nil
}

type status string

const (
	Unknown status = "Unknown"
	AC      status = "AC"
	WA      status = "WA"
	TLE     status = "TLE"
	MLE     status = "MLE"
	RE      status = "RE"
	CE      status = "CE"
	QLE     status = "QLE"
	OLE     status = "OLE"
	IE      status = "IE"
	WJ      status = "WJ"
	WR      status = "WR"
	Judging status = "Judging"
)

func (s status) withColor() aurora.Value {
	// Handle cases like "12/15 TLE"
	var prefix status
	if sp := strings.Split(string(s), " "); len(sp) == 2 {
		prefix = status(sp[0] + " ")
		s = status(sp[1])
	}
	var c func(interface{}) aurora.Value
	switch s {
	case AC:
		c = aurora.Green
	case WA, TLE, MLE, RE, CE, QLE, OLE, IE:
		c = aurora.Yellow
	default:
		c = aurora.BrightBlack
	}
	return c(prefix + s)
}

func (s status) isCompleted() bool {
	switch s {
	case AC, WA, TLE, MLE, RE, CE, QLE, OLE, IE:
		return true
	}
	return false
}

type submission struct {
	time          time.Time
	task          string
	language      string
	score         int
	codeSizeBytes int
	status        status
	execTime      time.Duration
	memoryKB      int
	id            string
}

func (s *submission) WriteTo(w io.Writer) {
	fmt.Fprintf(w, "%s\t%s\t%d\t%d Byte\t%s\t%s\t%d KB\n",
		s.time.Format("2006-01-02 15:03:04"), aurora.Cyan(s.task), s.score, s.codeSizeBytes, s.status.withColor(), s.execTime, s.memoryKB)
}

// <td class="no-break"><time class='fixtime fixtime-second'>2021-03-19 11:48:22+0900</time></td>
var reTime = regexp.MustCompile(`<time class='fixtime fixtime-second'>(.*)</time>`)

func parseTime(td string) (time.Time, bool) {
	m := reTime.FindStringSubmatch(td)
	if len(m) == 2 {
		t, err := time.Parse("2006-01-02 15:04:05-0700", m[1])
		if err == nil {
			return t, true
		}
	}
	return time.Time{}, false
}

// <td><a href="/contests/abc195/tasks/abc195_b">B - Many Oranges</a></td>
var reTask = regexp.MustCompile(`>([^>]+?)</a></td>`)

func parseTask(td string) (string, bool) {
	m := reTask.FindStringSubmatch(td)
	if len(m) == 2 {
		return m[1], true
	}
	return "", false
}

// <td><a href="/contests/abc195/submissions/me?f.Language=4026">Go (1.14.1)</a></td>
var reLanguage = regexp.MustCompile(`>([^>]+?)</a></td>`)

func parseLanguage(td string) (string, bool) {
	m := reLanguage.FindStringSubmatch(td)
	if len(m) == 2 {
		return html.UnescapeString(m[1]), true
	}
	return "", false
}

// <td class="text-right submission-score" data-id="20882710">200</td>
var reScore = regexp.MustCompile(`>([0-9]+)</td>`)

func parseScore(td string) (int, bool) {
	m := reScore.FindStringSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(m[1])
		if err == nil {
			return i, true
		}
	}
	return 0, false
}

// <td class="text-right">6655 Byte</td>
var reCodeSizeBytes = regexp.MustCompile(`>([0-9]+) Byte</td>`)

func parseCodeSizeBytes(td string) (int, bool) {
	m := reCodeSizeBytes.FindStringSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(m[1])
		if err == nil {
			return i, true
		}
	}
	return 0, false
}

// <td class='text-center'><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
var reStatus = regexp.MustCompile(`>([^>]+?)</span>`)

func parseStatus(td string) (status, bool) {
	m := reStatus.FindStringSubmatch(td)
	if len(m) == 2 {
		return status(m[1]), true
	}
	return Unknown, false
}

// <td class="text-center"><a href="/contests/abc195/submissions/21027486">Detail</a></td>
var reID = regexp.MustCompile(`"/contests/abc195/submissions/(.+)"`)

func parseID(td string) (string, bool) {
	m := reID.FindStringSubmatch(td)
	if len(m) == 2 {
		return m[1], true
	}
	return "", false
}

// <td class='text-right'>19 ms</td>
var reExecTime = regexp.MustCompile(`>([0-9]+) ms</td>`)

func parseExecTime(td string) (time.Duration, bool) {
	m := reExecTime.FindStringSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(m[1])
		if err == nil {
			return time.Duration(i) * time.Millisecond, true
		}
	}
	return 0, false
}

// <td class='text-right'>11540 KB</td>
var reMemoryKB = regexp.MustCompile(`>([0-9]+) KB</td>`)

func parseMemoryKB(td string) (int, bool) {
	m := reMemoryKB.FindStringSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(m[1])
		if err == nil {
			return i, true
		}
	}
	return 0, false
}

var reTR = regexp.MustCompile(`(?s)<tr>(.*?)</tr>`)
var reTD = regexp.MustCompile(`(?s)(<td.*?</td>)`)

// Returned submissions are sorted by submission time in the ascending order (opposite of the web page).
func getRecentSubmissions(client *http.Client, contestID string) ([]*submission, error) {
	resp, err := client.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/submissions/me", contestID))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	var ss []*submission
	for _, tr := range reTR.FindAllStringSubmatch(string(buf), -1) {
		tds := reTD.FindAllStringSubmatch(tr[0], -1)
		if len(tds) == 0 {
			continue
		}
		if len(tds) != 8 && len(tds) != 10 {
			log.Println("Unexpected td:", tds)
			return nil, errors.New("failed to parse submissions")
		}
		s := &submission{}
		ss = append(ss, s)
		if t, ok := parseTime(tds[0][0]); ok {
			s.time = t
		}
		if t, ok := parseTask(tds[1][0]); ok {
			s.task = t
		}
		if l, ok := parseLanguage(tds[3][0]); ok {
			s.language = l
		}
		if sc, ok := parseScore(tds[4][0]); ok {
			s.score = sc
		}
		if cs, ok := parseCodeSizeBytes(tds[5][0]); ok {
			s.codeSizeBytes = cs
		}
		if st, ok := parseStatus(tds[6][0]); ok {
			s.status = st
		}
		if len(tds) == 8 {
			if i, ok := parseID(tds[7][0]); ok {
				s.id = i
			}
			continue
		}
		if d, ok := parseExecTime(tds[7][0]); ok {
			s.execTime = d
		}
		if m, ok := parseMemoryKB(tds[8][0]); ok {
			s.memoryKB = m
		}
		if i, ok := parseID(tds[9][0]); ok {
			s.id = i
		}
	}
	// Reverse the order to make it ascending in time.
	for i, j := 0, len(ss)-1; i < j; {
		ss[i], ss[j] = ss[j], ss[i]
		i++
		j--
	}
	return ss, nil
}

type SubmissionStatus struct {
	Html     string
	Interval int
	Score    string
}

func getSubmissionStatus(contestID, submissionID string) (*SubmissionStatus, error) {
	// TODO: Check if this is OK during the contest.
	resp, err := http.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/submissions/%s/status/json", contestID, submissionID))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	s := SubmissionStatus{}
	if err := decoder.Decode(&s); err != nil {
		return nil, err
	}
	return &s, nil
}

type SubmissionStatusMulti struct {
	Result map[string]SubmissionStatus
}

func getDetailedSubmissionStatus(client *http.Client, contestID, submissionID string) (*SubmissionStatus, error) {
	resp, err := client.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/submissions/me/status/json?sids[]=%s", contestID, submissionID))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	s := SubmissionStatusMulti{}
	if err := decoder.Decode(&s); err != nil {
		return nil, err
	}
	st, ok := s.Result[submissionID]
	if !ok {
		return nil, errors.New("no status info found in the response")
	}
	return &st, nil
}

func run(contestID string) error {
	client, err := newClient()
	if err != nil {
		return err
	}
	log.Printf("Getting recent submissions for %s", contestID)
	ss, err := getRecentSubmissions(client, contestID)
	if err != nil {
		return err
	}

	if len(ss) > 0 {
		w := tabwriter.NewWriter(os.Stdout, 0, 0, 1, ' ', 0)
		fmt.Fprintf(w, "Submission Time\t%s\tScore\tCode Size\t%s\tExec Time\tMemory\n",
			aurora.White("Task"), aurora.White("Status"))
		for _, s := range ss {
			s.WriteTo(w)
		}
		w.Flush()

		last := ss[len(ss)-1]
		if !last.status.isCompleted() {
			for {
				status, err := getSubmissionStatus(contestID, last.id)
				if err != nil {
					return err
				}
				if status.Interval == 0 {
					status, err = getDetailedSubmissionStatus(client, contestID, last.id)
					if err != nil {
						return err
					}
					if st, ok := parseStatus(status.Html); !ok {
						log.Println("Failed to parse status", status.Html)
					} else {
						last.status = st
					}
					if t, ok := parseExecTime(status.Html); !ok {
						log.Println("Failed to parse exec time", status.Html)
					} else {
						last.execTime = t
					}
					if m, ok := parseMemoryKB(status.Html); !ok {
						log.Println("Failed to parse memory kb", status.Html)
					} else {
						last.memoryKB = m
					}
					if i, err := strconv.Atoi(status.Score); err != nil {
						log.Println("Failed to parse score:", err)
					} else {
						last.score = i
					}
					last.WriteTo(w)
					w.Flush()
					break
				} else {
					st, ok := parseStatus(status.Html)
					if !ok {
						log.Println("Failed to parse status", status.Html)
					} else {
						last.status = st
						last.WriteTo(w)
						w.Flush()
					}
					<-time.NewTimer(time.Duration(status.Interval) * time.Millisecond).C
				}
			}
		}
	}
	return nil
}

func main() {
	if err := run(os.Args[1]); err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
}
