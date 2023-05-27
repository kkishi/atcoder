#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, z);
  strings(s);
  V<int> dp(2);
  dp[0] = 0;
  dp[1] = big;
  each(e, s) {
    chmin(dp[0], dp[1] + z);
    chmin(dp[1], dp[0] + z);
    int c = e == 'A';
    V<int> ndp(2, big);
    rep(i, 2) {
      {
        char nc = i;
        if (c == nc) {
          chmin(ndp[i], dp[i] + x);
        }
      }
      {
        char nc = i ^ 1;
        if (c == nc) {
          chmin(ndp[i], dp[i] + y);
        }
      }
    }
    swap(dp, ndp);
  }
  wt(min(dp));
}
