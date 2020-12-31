#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<V<V<int>>> f(n, V<V<int>>(5, V<int>(2)));
  cin >> f;
  VV<int> p(n, V<int>(11));
  cin >> p;
  int ans = numeric_limits<int>::min();
  rep(s, 1, 1 << 10) {
    V<int> c(n);
    rep(i, 5) rep(j, 2) {
      int k = i * 2 + j;
      if (hasbit(s, k)) {
        rep(l, n) if (f[l][i][j] == 1)++ c[l];
      }
    }
    int sum = 0;
    rep(i, n) sum += p[i][c[i]];
    chmax(ans, sum);
  }
  wt(ans);
}
