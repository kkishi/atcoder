#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector dp(1002, vector(1002, int(0)));
  rep(n) {
    ints(lx, ly, rx, ry);
    ++dp[lx][ly];
    --dp[rx][ly];
    --dp[lx][ry];
    ++dp[rx][ry];
  }
  rep(y, 1001) rep(x, 1, 1001) dp[x][y] += dp[x - 1][y];
  rep(x, 1001) rep(y, 1, 1001) dp[x][y] += dp[x][y - 1];
  V<int> ans(n + 1);
  rep(x, 1001) rep(y, 1001)++ ans[dp[x][y]];
  rep(i, n) wt(ans[i + 1]);
}
