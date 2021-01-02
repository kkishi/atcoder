#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l);
  V<int> a(l);
  cin >> a;

  vector dp(l + 1, vector(5, big));
  rep(i, 5) dp[0][i] = 0;

  rep(i, l) {
    int x = a[i] == 0 ? 0 : 2 - a[i] % 2;
    int c2 = abs(x - 2);
    int c1 = abs(x - 1);
    int c[] = {a[i], c2, c1, c2, a[i]};
    rep(j, 5) rep(k, j + 1) chmin(dp[i + 1][j], dp[i][k] + c[k]);
  }

  int ans = big;
  rep(i, 5) chmin(ans, dp[l][i]);
  wt(ans);
}
