#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "disjoint_set.h"
#include "geometry.h"

void Main() {
  ints(n);
  V<Point> p(n);
  cin >> p;
  wt(BinarySearch<double>(0, 100, [&](double x) {
    DisjointSet ds(n + 2);
    int u = n, d = n + 1;
    rep(i, n) {
      double y = p[i].y;
      if (abs(100 - y) < x * 2) ds.Union(i, u);
      if (abs(y + 100) < x * 2) ds.Union(i, d);
      rep(j, i + 1, n) if ((p[j] - p[i]).Norm() < x * 2) ds.Union(i, j);
    }
    return !ds.Same(u, d);
  }));
}
