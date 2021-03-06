#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> x(n), y(n);
  V<char> c(n);
  rep(i, n) cin >> x[i] >> y[i] >> c[i];

  int K = k * 4;
  vector grid(K, V<int>(K));
  rep(i, n) {
    int xi = x[i], yi = y[i];
    if (c[i] == 'W') {
      xi += k;
    }
    xi %= K;
    yi %= K;
    set<pair<int, int>> seen;
    auto add = [&](int a, int b) {
      if (seen.insert({a, b}).second) {
        ++grid[a][b];
      }
    };
    rep(i, 4) rep(j, 4) if (even(i + j)) {
      add((xi + k * i) % K, (yi + k * j) % K);
    }
  }

  vector sum(K + 1, V<int>(K + 1));
  rep(i, K) rep(j, K) {
    sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + grid[i][j];
  }

  int ans = 0;
  rep(i, k, K + 1) rep(j, k, K + 1)
      chmax(ans, sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k]);
  wt(ans);
}
