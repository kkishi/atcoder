#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, ma, mb);
  V<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  const int maxi = 10 * n;
  VV<int> dp(maxi + 1, V<int>(maxi + 1, big));
  dp[0][0] = 0;
  rep(i, n) {
    rrep(ai, a[i], maxi + 1) rrep(bi, b[i], maxi + 1) {
      chmin(dp[ai][bi], dp[ai - a[i]][bi - b[i]] + c[i]);
    }
  }
  int ans = big;
  for (int i = 1; i * max(ma, mb) <= maxi; ++i) {
    chmin(ans, dp[ma * i][mb * i]);
  }
  wt(ans == big ? -1 : ans);
}
