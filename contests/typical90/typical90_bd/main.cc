#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s);
  VV<int> v(2, V<int>(n));
  rep(i, n) rep(j, 2) cin >> v[j][i];
  vector dp(n + 1, vector(s + 1, int(-1)));
  dp[0][0] = 0;
  rep(i, n) rep(j, 2) {
    int x = v[j][i];
    rep(k, x, s + 1) if (dp[i][k - x] != -1) dp[i + 1][k] = j;
  }
  if (dp[n][s] == -1) {
    wt("Impossible");
    return;
  }
  int i = s;
  string ans;
  rrep(j, n) {
    int k = dp[j + 1][i];
    ans += (char)('A' + k);
    i -= v[k][j];
  }
  reverse(ans);
  wt(ans);
}
