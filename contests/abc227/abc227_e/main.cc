#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  each(e, s) e = e == 'K' ? 0 : e == 'E' ? 1 : 2;
  int n = sz(s);
  vector dp(n + 1, vector(n * n, vector(n + 1, vector(n + 1, int(0)))));
  dp[0][0][0][0] = 1;
  rep(i, n) rep(x, n * n) rep(e, i + 1) rep(y, i + 1 - e) {
    if (dp[i][x][e][y] == 0) continue;
    string S;
    array<int, 3> use = {i - e - y, e, y};
    each(e, s) if (use[e] == 0) S += e;
    else --use[e];
    rep(I, 3) rep(j, sz(S)) if (S[j] == I) {
      dp[i + 1][x + j][e + (I == 1)][y + (I == 2)] += dp[i][x][e][y];
      break;
    }
  }
  int ans = 0;
  V<int> sum(3);
  each(e, s)++ sum[e];
  ints(k);
  rep(i, min(k + 1, n * n)) ans += dp[n][i][sum[1]][sum[2]];
  wt(ans);
}
