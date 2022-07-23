#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> x(n);
  cin >> x;
  V<int> Y(n);
  rep(m) {
    ints(c, y);
    Y[c - 1] = y;
  }
  vector dp(n + 1, -big);
  dp[0] = 0;
  rep(I, n) {
    vector ndp(n + 1, -big);
    rep(i, n) {
      chmax(ndp[0], dp[i]);
      chmax(ndp[i + 1], dp[i] + x[I] + Y[i]);
    }
    swap(dp, ndp);
  }
  wt(max(dp));
}
