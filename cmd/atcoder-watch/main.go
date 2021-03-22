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
	"os"
	"regexp"
	"strconv"
	"strings"
	"text/tabwriter"
	"time"

	"github.com/kkishi/atcoder/pkg/client"

	aurora "github.com/logrusorgru/aurora/v3"
)

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

func parseTime(td []byte) (time.Time, bool) {
	m := reTime.FindSubmatch(td)
	if len(m) == 2 {
		t, err := time.Parse("2006-01-02 15:04:05-0700", string(m[1]))
		if err == nil {
			return t, true
		}
	}
	return time.Time{}, false
}

// <td><a href="/contests/abc195/tasks/abc195_b">B - Many Oranges</a></td>
var reTask = regexp.MustCompile(`>([^>]+?)</a></td>`)

func parseTask(td []byte) (string, bool) {
	m := reTask.FindSubmatch(td)
	if len(m) == 2 {
		return string(m[1]), true
	}
	return "", false
}

// <td><a href="/contests/abc195/submissions/me?f.Language=4026">Go (1.14.1)</a></td>
var reLanguage = regexp.MustCompile(`>([^>]+?)</a></td>`)

func parseLanguage(td []byte) (string, bool) {
	m := reLanguage.FindSubmatch(td)
	if len(m) == 2 {
		return html.UnescapeString(string(m[1])), true
	}
	return "", false
}

// <td class="text-right submission-score" data-id="20882710">200</td>
var reScore = regexp.MustCompile(`>([0-9]+)</td>`)

func parseScore(td []byte) (int, bool) {
	m := reScore.FindSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(string(m[1]))
		if err == nil {
			return i, true
		}
	}
	return 0, false
}

// <td class="text-right">6655 Byte</td>
var reCodeSizeBytes = regexp.MustCompile(`>([0-9]+) Byte</td>`)

func parseCodeSizeBytes(td []byte) (int, bool) {
	m := reCodeSizeBytes.FindSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(string(m[1]))
		if err == nil {
			return i, true
		}
	}
	return 0, false
}

// <td class='text-center'><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
var reStatus = regexp.MustCompile(`>([^>]+?)</span>`)

func parseStatus(td []byte) (status, bool) {
	m := reStatus.FindSubmatch(td)
	if len(m) == 2 {
		return status(m[1]), true
	}
	return Unknown, false
}

// <td class="text-center"><a href="/contests/abc195/submissions/21027486">Detail</a></td>
var reID = regexp.MustCompile(`/submissions/([^"]+)"`)

func parseID(td []byte) (string, bool) {
	m := reID.FindSubmatch(td)
	if len(m) == 2 {
		return string(m[1]), true
	}
	return "", false
}

// <td class='text-right'>19 ms</td>
var reExecTime = regexp.MustCompile(`>([0-9]+) ms</td>`)

func parseExecTime(td []byte) (time.Duration, bool) {
	m := reExecTime.FindSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(string(m[1]))
		if err == nil {
			return time.Duration(i) * time.Millisecond, true
		}
	}
	return 0, false
}

// <td class='text-right'>11540 KB</td>
var reMemoryKB = regexp.MustCompile(`>([0-9]+) KB</td>`)

func parseMemoryKB(td []byte) (int, bool) {
	m := reMemoryKB.FindSubmatch(td)
	if len(m) == 2 {
		i, err := strconv.Atoi(string(m[1]))
		if err == nil {
			return i, true
		}
	}
	return 0, false
}

var reTR = regexp.MustCompile(`(?s)<tr>(.*?)</tr>`)
var reTD = regexp.MustCompile(`(?s)(<td.*?</td>)`)

// Returned submissions are sorted by submission time in the ascending order (opposite of the web page).
func getRecentSubmissions(c *http.Client, contestID string) ([]*submission, error) {
	resp, err := c.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/submissions/me", contestID))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	var ss []*submission
	for _, tr := range reTR.FindAllSubmatch(buf, -1) {
		tds := reTD.FindAllSubmatch(tr[0], -1)
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
	Html     []byte
	Interval int
	Score    string
}

func getSubmissionStatus(c *http.Client, contestID, submissionID string) (*SubmissionStatus, error) {
	resp, err := c.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/submissions/%s/status/json", contestID, submissionID))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	s := SubmissionStatus{}
	if err := decoder.Decode(&s); err != nil {
		return nil, fmt.Errorf("failed to parse submission status: %s", err)
	}
	return &s, nil
}

type SubmissionStatusMulti struct {
	Result map[string]SubmissionStatus
}

func getDetailedSubmissionStatus(c *http.Client, contestID, submissionID string) (*SubmissionStatus, error) {
	resp, err := c.Get(fmt.Sprintf("https://atcoder.jp/contests/%s/submissions/me/status/json?sids[]=%s", contestID, submissionID))
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	s := SubmissionStatusMulti{}
	if err := decoder.Decode(&s); err != nil {
		return nil, fmt.Errorf("failed to parse submission status (multi): %s", err)
	}
	st, ok := s.Result[submissionID]
	if !ok {
		return nil, errors.New("no status info found in the response")
	}
	return &st, nil
}

func run(contestID string) error {
	c, err := client.New()
	if err != nil {
		return err
	}
	log.Printf("Getting recent submissions for %s", contestID)
	ss, err := getRecentSubmissions(c, contestID)
	if err != nil {
		return err
	}

	if len(ss) > 0 {
		w := tabwriter.NewWriter(os.Stdout, 0, 0, 1, ' ', 0)
		fmt.Fprintf(w, "SubmissionTime\t%s\tScore\tCodeSize\t%s\tExecTime\tMemory\n",
			aurora.White("Task"), aurora.White("Status"))
		for _, s := range ss {
			s.WriteTo(w)
		}
		w.Flush()

		last := ss[len(ss)-1]
		var lastStatus status
		if !last.status.isCompleted() {
			for {
				status, err := getSubmissionStatus(c, contestID, last.id)
				if err != nil {
					return err
				}
				if status.Interval == 0 {
					status, err = getDetailedSubmissionStatus(c, contestID, last.id)
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
						if st != lastStatus {
							lastStatus = st
							last.status = st
							last.WriteTo(w)
							w.Flush()
						}
					}
					<-time.NewTimer(time.Duration(status.Interval) * time.Millisecond).C
				}
			}
		}
	}
	return nil
}

func main() {
	log.SetFlags(log.Flags() | log.Lmicroseconds)
	if err := run(os.Args[1]); err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
}
