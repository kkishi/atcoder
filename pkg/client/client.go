package client

import (
	"errors"
	"fmt"
	"io/ioutil"
	"net/http"
	"net/http/cookiejar"
	"net/url"
	"os/user"
	"path/filepath"
	"regexp"
	"strings"

	"golang.org/x/net/publicsuffix"
)

func New() (*http.Client, error) {
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
	m := regexp.MustCompile(`REVEL_SESSION="([^"]+)"`).FindSubmatch(b)
	if len(m) != 2 {
		return nil, errors.New("REVEL_SESSION not found")
	}
	jar.SetCookies(u, []*http.Cookie{
		{
			Name:   "REVEL_SESSION",
			Value:  string(m[1]),
			Path:   "/",
			Domain: "atcoder.jp",
		},
	})
	return &http.Client{
		Jar: jar,
		CheckRedirect: func(req *http.Request, via []*http.Request) error {
			if strings.HasPrefix(req.URL.String(), "https://atcoder.jp/login") {
				return fmt.Errorf("request got redirected to %s, check if you are logged in", req.URL)
			}
			return nil
		},
	}, nil
}
