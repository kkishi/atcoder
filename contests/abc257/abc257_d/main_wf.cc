#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n), p(n);
  rep(i, n) cin >> x[i] >> y[i] >> p[i];
  vector d(n, vector(n, int(0)));
  rep(i, n) rep(j, n) d[i][j] =
      div_ceil(abs(x[j] - x[i]) + abs(y[j] - y[i]), p[i]);
  // Warshall Floyd
  rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], max(d[i][k], d[k][j]));
  int ans = big;
  rep(i, n) {
    int x = 0;
    rep(j, n) chmax(x, d[i][j]);
    chmin(ans, x);
  }
  wt(ans);
}
