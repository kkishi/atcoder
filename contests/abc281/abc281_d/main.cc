#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, d);
  V<int> a(n);
  cin >> a;
  vector dp(k + 1, vector(d, int(-1)));
  dp[0][0] = 0;
  each(e, a) {
    vector ndp = dp;
    rep(i, k) rep(j, d) {
      if (dp[i][j] == -1) continue;
      int inc = (j + e) / d;
      chmax(ndp[i + 1][(j + e) % d], dp[i][j] + inc);
    }
    swap(dp, ndp);
  }
  if (dp[k][0] == -1) {
    wt(-1);
  } else {
    wt(dp[k][0] * d);
  }
}
