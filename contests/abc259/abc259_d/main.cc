#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, sx, sy, tx, ty);
  int s = n, t = s + 1;
  DisjointSet ds(n + 2);
  V<pair<int, int>> p(n);
  V<int> r(n);
  rep(i, n) {
    cin >> p[i] >> r[i];
#define sq(x) (int(x) * int(x))
    if (sq(p[i].first - sx) + sq(p[i].second - sy) == sq(r[i])) ds.Union(s, i);
    if (sq(p[i].first - tx) + sq(p[i].second - ty) == sq(r[i])) ds.Union(t, i);
  }
  rep(i, n) rep(j, i) {
    int cd = sq(p[i].first - p[j].first) + sq(p[i].second - p[j].second);
    if (cd > sq(r[i] + r[j])) continue;
    auto inside = [&](int i, int j) {
      return r[i] > r[j] && cd < sq(r[i] - r[j]);
    };
    if (inside(i, j) || inside(j, i)) continue;
    ds.Union(i, j);
  }
  wt(ds.Same(s, t));
}
