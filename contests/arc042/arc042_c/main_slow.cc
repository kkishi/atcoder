#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector dp(p + 101, vector(101, 0));
  rep(i, n) {
    rrep(j, p + 101 - a[i]) rrep(k, 101)
        chmax(dp[j + a[i]][min(k, a[i])], dp[j][k] + b[i]);
  }
  int ans = 0;
  rep(i, p + 101) rep(j, 101) if (i - j <= p) chmax(ans, dp[i][j]);
  wt(ans);
}
