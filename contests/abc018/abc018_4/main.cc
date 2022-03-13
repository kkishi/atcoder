#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, p, q, r);
  V<int> x(r), y(r), z(r);
  rep(i, r) cin >> x[i] >> y[i] >> z[i];
  int ans = 0;
  rep(s, 1 << n) if (popcount(s) == p) {
    V<int> v(m);
    rep(i, r) if (hasbit(s, x[i] - 1)) v[y[i] - 1] += z[i];
    sort(v, greater{});
    int sum = 0;
    rep(i, q) sum += v[i];
    chmax(ans, sum);
  }
  wt(ans);
}
