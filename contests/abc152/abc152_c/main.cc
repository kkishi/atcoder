#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  int m = big;
  int ans = 0;
  rep(i, N) {
    ints(p);
    chmin(m, p);
    if (m >= p) ++ans;
  }
  wt(ans);
}
