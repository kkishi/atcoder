#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  vector dp(x + 1 + 100, false);
  dp[0] = true;
  rep(n) {
    ints(a, b);
    rep(b) rrep(i, x) if (dp[i]) dp[i + a] = true;
  }
  wt(dp[x] == true);
}
