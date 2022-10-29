#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  vector dp(m + 1, vector(2, big));
  dp[0][1] = 0;
  rep(i, n) {
    vector ndp(m + 1, vector(2, big));
    rep(j, m + 1) rep(k, 2) {
      if (dp[j][k] == big) continue;
      chmin(ndp[j][0], dp[j][k] + (k == 1));
      int nj = j + a[i];
      if (nj > m) continue;
      chmin(ndp[nj][1], dp[j][k]);
    }
    swap(dp, ndp);
  }
  rep(i, 1, m + 1) {
    int ans = min(dp[i][0], dp[i][1]);
    if (ans == big) ans = -1;
    wt(ans);
  }
}
