#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(c);
  string bs = "ABXY";
  int ans = big;
  each(l0, bs) each(l1, bs) each(r0, bs) each(r1, bs) {
    V<string> v{{l0, l1}, {r0, r1}};
    string C = c;
    int cnt = 0;
    while (!C.empty()) {
      if (sz(C) >= 2) {
        each(e, v) {
          if (C.substr(sz(C) - 2, 2) == e) {
            rep(2) C.pop_back();
            goto next;
          }
        }
      }
      C.pop_back();
    next:
      ++cnt;
    }
    chmin(ans, cnt);
  }
  wt(ans);
}
