#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<pair<int, int>> v(5001);
  rep(n) {
    ints(d, c, s);
    v[d].eb(c, s);
  }
  V<int> dp(5001);
  int ans = 0;
  rrep(i, 5001) {
    chmax(ans, dp[i]);
    each(c, s, v[i]) {
      V<int> ndp = dp;
      int ans2 = ans;
      for (int j = 0; i - j - c >= 0; ++j) {
        chmax(ans2, dp[i - j]);
        chmax(ndp[i - j - c], ans2 + s);
      }
      swap(dp, ndp);
    }
  }
  wt(ans);
}
