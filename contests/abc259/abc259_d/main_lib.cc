#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "int_geometry.h"

void Main() {
  ints(n, sx, sy, tx, ty);
  V<Circle> c(n);
  rep(i, n) cin >> c[i].c >> c[i].r;
  c.pb({{sx, sy}, 0});
  c.pb({{tx, ty}, 0});
  DisjointSet ds(n + 2);
  rep(i, n + 2) rep(j, i) if (Intersects(c[i], c[j])) ds.Union(i, j);
  wt(ds.Same(n, n + 1));
}
