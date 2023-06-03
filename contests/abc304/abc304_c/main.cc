#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "int_geometry.h"

void Main() {
  ints(n, d);
  DisjointSet ds(n);
  V<Point> v(n);
  cin >> v;
  rep(i, n) rep(j, i + 1, n) if (Norm(v[j] - v[i]) <= d * d) ds.Union(i, j);
  rep(i, n) wt(ds.Same(0, i));
}
