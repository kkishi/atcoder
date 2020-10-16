#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, T);
  int ans = 1000000;
  rep(i, n) {
    ints(c, t);
    if (t <= T) chmin(ans, c);
  }
  if (ans == 1000000) {
    wt("TLE");
  } else {
    wt(ans);
  }
}
