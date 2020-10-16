#include <bits/stdc++.h>

#include "atcoder.h"

#define FOR(i, n) for (auto i : (n))

template <class iter>
string conv(iter begin, iter end) {
  string s;
  for (; begin != end; ++begin) {
    if (s.empty() || s.back() < *begin) {
      s += *begin;
    }
  }
  return s;
}

string simulate(const string& s) {
  string ret;
  rep(i, s.size() - 1) { ret += '0' + abs(s[i] - s[i + 1]); }
  return ret;
}

string simplify(const string& s) {
  string ret;
  FOR(c, s) {
    if (ret.size() >= 2 && ret.back() == c && ret[ret.size() - 2] == c) {
      continue;
    }
    ret += c;
  }
  return ret;
}

void Main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string l = conv(all(S));
  string r = conv(S.rbegin(), S.rend());
  dbg(l, r);
  /*
  reverse(all(r));
  string s = l.substr(0, l.size() - 1) + r;
  dbg(l, r, s);
  */

  /*
  while (s.size() > 1) {
    s = simulate(s);
    dbg(s);
  }
  cout << s << endl;
  */
  char maximum = '0';
  FOR(c, S) chmax(maximum, c);
  dbg(maximum);
  int cnt = 0;
  FOR(c, S) if (c == maximum)++ cnt;

  reverse(all(r));

  string s;
  if (cnt & 1) {
    s = l.substr(0, l.size() - 1) + r;
  } else {
    s = l + r;
  }
  dbg(s);

  while (s.size() > 1) {
    s = simulate(s);
    dbg(s);
  }
  // cout << s << endl;

  string naive = S;
  while (naive.size() > 1) {
    naive = simulate(naive);
    dbg(naive);
  }
  if (s != naive) {
    dbg("FAIL");
  }

  string fast = S;
  while (fast.size() > 1) {
    fast = simulate(fast);
    dbg(fast);
    fast = simplify(fast);
    dbg(fast);
  }
  if (fast != naive) {
    dbg("FAIL");
  }
  cout << fast << endl;
}
