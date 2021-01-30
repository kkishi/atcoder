#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s, t);
  int m = min(sz(s), sz(t));
  int ans = sz(s) + sz(t);
  rep(i, 1, m + 1) {
    if (s.substr(sz(s) - i) == t.substr(0, i)) {
      int x = sz(s) + sz(t) - i;
      if (x >= n) chmin(ans, x);
    }
  }
  wt(ans);
}
