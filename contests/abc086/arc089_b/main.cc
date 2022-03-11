#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

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

  CumulativeSum2D sum(grid);

  int ans = 0;
  rep(i, K - k + 1) rep(j, K - k + 1) {
    chmax(ans, sum.Get(i, j, i + k - 1, j + k - 1));
  }
  wt(ans);
}
