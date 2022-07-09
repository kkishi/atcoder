#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, sx, sy, tx, ty);
  V<pair<int, int>> p(n);
  V<int> r(n);
  rep(i, n) cin >> p[i] >> r[i];
  p.eb(sx, sy);
  p.eb(tx, ty);
  r.eb(0);
  r.eb(0);
  DisjointSet ds(n + 2);
  rep(i, n + 2) rep(j, i) {
#define sq(x) ((x) * (x))
    int cd = sq(p[i].first - p[j].first) + sq(p[i].second - p[j].second);
    if (cd > sq(r[i] + r[j])) continue;
    auto inside = [&](int i, int j) {
      return r[i] > r[j] && cd < sq(r[i] - r[j]);
    };
    if (inside(i, j) || inside(j, i)) continue;
    ds.Union(i, j);
  }
  wt(ds.Same(n, n + 1));
}
