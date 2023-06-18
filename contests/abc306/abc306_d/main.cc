#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> dp(2);
  rep(n) {
    ints(x, y);
    V<int> ndp = {-big, -big};
    rep(i, 2) {
      chmax(ndp[i], dp[i]);
      int ni;
      if (i == 0) {
        if (x == 0) {
          ni = 0;
        } else {
          ni = 1;
        }
      } else {
        if (x == 0) {
          ni = 0;
        } else {
          continue;
        }
      }
      chmax(ndp[ni], dp[i] + y);
    }
    swap(dp, ndp);
  }
  wt(max(dp));
}
