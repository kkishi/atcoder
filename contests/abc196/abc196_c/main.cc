#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  int t = 1;
  rep(i, 1, 7) {
    t *= 10;
    rep(j, t / 10, t) {
      if (j * t + j <= n) ++ans;
    }
  }
  wt(ans);
}
