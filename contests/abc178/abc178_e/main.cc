#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  int ans = -big;
  rep(2) {
    int maxi = -big, mini = big;
    rep(i, n) {
      chmax(maxi, x[i] + y[i]);
      chmin(mini, x[i] + y[i]);
    }
    chmax(ans, maxi - mini);

    rep(i, n) {
      int tmp = y[i];
      y[i] = x[i];
      x[i] = 1000000001 - tmp;
    }
  }
  wt(ans);
}
