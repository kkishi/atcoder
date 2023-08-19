#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> c(n), p(n);
  VV<int> s(n);
  rep(i, n) {
    cin >> c[i] >> p[i];
    s[i].resize(p[i]);
    cin >> s[i];
  }
  vector dp(m + 1, double(0));
  rrep(i, m) {
    dp[i] = big;
    rep(j, n) {
      double sum = 0;
      int z = 0;
      rep(k, p[j]) {
        if (s[j][k] == 0) {
          ++z;
        } else {
          sum += dp[min(i + s[j][k], m)] / p[j];
        }
      }
      chmin(dp[i], (double)p[j] / (p[j] - z) * (c[j] + sum));
    }
  }
  wt(dp[0]);
}
