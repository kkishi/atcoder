#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  V<int> x(n), y(n);
  cin >> x >> y;
  V<int> a(m), b(m), z(m);
  rep(i, m) cin >> a[i] >> b[i] >> z[i];

  int ans = big;
  rep(ux, 2) rep(uy, 2) {
    V<tuple<int, int, int>> es;
    rep(i, m) es.eb(z[i], a[i] - 1, b[i] - 1);
    if (ux) rep(i, n) es.eb(x[i], i, n);
    if (uy) rep(i, n) es.eb(y[i], i, n + 1);
    sort(es);

    int sum = 0;
    DisjointSet ds(n + 2);
    for (auto [z, a, b] : es) {
      if (ds.Same(a, b)) continue;
      sum += z;
      ds.Union(a, b);
    }
    if (ds.Size(0) == n + ux + uy) {
      chmin(ans, sum);
    }
  }
  wt(ans);
}
