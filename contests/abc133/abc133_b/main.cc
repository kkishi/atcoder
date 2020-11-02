#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  VV<int> xs(n, V<int>(d));
  cin >> xs;
  int ans = 0;
  rep(i, n - 1) rep(j, i + 1, n) {
    int sum = 0;
    auto sq = [](int x) { return x * x; };
    rep(k, d) sum += sq(xs[i][k] - xs[j][k]);
    for (int k = 0; k * k <= sum; ++k) {
      if (k * k == sum) ++ans;
    }
  }
  wt(ans);
}
