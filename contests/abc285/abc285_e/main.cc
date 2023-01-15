#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> dp(n);
  int ans = 0;
  V<int> f(n);
  rep(i, 1, n) f[i] = f[i - 1] + a[(i - 1) / 2];
  rep(i, n) {
    rep(j, i) chmax(dp[i], dp[j] + f[i - j - 1]);
    chmax(ans, dp[i] + f[n - 1 - i]);
  }
  wt(ans);
}
