#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  map<int, int> cnt;
  each(c, s) cnt[c - '0']++;
  bool ok = false;
  int len = min(sz(s), 3);
  int ten = 1;
  rep(i, len) ten *= 10;
  rep(i, ten) if (i % 8 == 0) {
    int x = i;
    map<int, int> m;
    rep(len) {
      ++m[x % 10];
      x /= 10;
    }
    bool ok2 = true;
    each(k, v, m) {
      if (cnt[k] < v) ok2 = false;
    }
    if (ok2) ok = true;
  }
  wt(ok);
}
