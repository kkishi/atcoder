#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> x(n, V<int>(3));
  V<int> idx(n);
  rep(i, n) {
    rep(j, 3) cin >> x[i][j];
    idx[i] = i;
  }
  int ans = 0;
  rep(s, 1 << 3) {
    auto f = [&](int i) {
      int ret = 0;
      rep(j, 3) { ret += x[i][j] * (hasbit(s, j) ? 1 : -1); }
      return ret;
    };
    sort(all(idx), [&](int a, int b) { return f(a) > f(b); });
    int sum = 0;
    rep(j, 3) {
      int tmp = 0;
      rep(i, m) { tmp += x[idx[i]][j]; }
      sum += abs(tmp);
    }
    chmax(ans, sum);
  }
  wt(ans);
}
