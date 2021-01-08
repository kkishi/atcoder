#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  strings(s, t);
  auto op = [](const string& a, const string& b) {
    string s = a + b;
    auto normalize = [&s] {
      // "AB" (-> "AAA") -> ""
      rep(i, sz(s) - 1) if (s[i] != s[i + 1]) {
        string ret;
        rep(j, sz(s)) if (j < i || i + 1 < j) ret += s[j];
        s = ret;
        return true;
      }
      // "AAA" -> ""
      rep(i, sz(s) - 2) if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
        string ret;
        rep(j, sz(s)) if (j < i || i + 2 < j) ret += s[j];
        s = ret;
        return true;
      }
      // "AA" -> "B"
      rep(i, sz(s) - 1) if (s[i] == s[i + 1]) {
        string ret;
        rep(j, sz(s)) {
          if (j < i || i + 1 < j) ret += s[j];
          if (j == i) ret += (char)('A' + 'B' - s[i]);
        }
        s = ret;
        return true;
      }
      return false;
    };
    while (normalize())
      ;
    return s;
  };
  SegmentTree<string> ts(sz(s), op), tt(sz(t), op);
  rep(i, sz(s)) ts.Set(i, s.substr(i, 1));
  rep(i, sz(t)) tt.Set(i, t.substr(i, 1));
  ints(q);
  rep(q) {
    ints(a, b, c, d);
    wt(ts.Aggregate(a - 1, b) == tt.Aggregate(c - 1, d) ? "YES" : "NO");
  }
}
