#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l);
  V<int> a(l);
  cin >> a;

  V<int> rsum(l + 1);
  rrep(i, l) rsum[i] = rsum[i + 1] + a[i];

  int ans = big;

  vector dp(l + 1, vector(3, big));
  rep(i, 3) dp[0][i] = 0;

  int sum = 0;
  rep(i, l) {
    int x;
    if (a[i] == 0) {
      x = 0;
    } else if (a[i] % 2 == 0) {
      x = 2;
    } else {
      x = 1;
    }
    int T1 = 0, O = 1, T2 = 2;

    int tc = abs(x - 2);
    int oc = abs(x - 1);

    // Skip
    if (x == 0 || x == 2) {
      chmin(dp[i + 1][T1], sum);
    } else {
      chmin(dp[i + 1][T1], sum + 1);
      chmin(dp[i + 1][O], sum + oc);
    }

    chmin(dp[i + 1][T1], dp[i][T1] + tc);
    chmin(dp[i + 1][O], dp[i][T1] + oc);
    chmin(dp[i + 1][O], dp[i][O] + oc);
    chmin(dp[i + 1][T2], dp[i][O] + tc);
    chmin(dp[i + 1][T2], dp[i][T2] + tc);

    rep(j, 3) chmin(ans, dp[i + 1][j] + rsum[i + 1]);

    sum += a[i];
  }

  wt(ans);
}
