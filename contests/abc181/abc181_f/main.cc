#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "disjointset.h"
#include "geometry.h"

using Vec = Vector<double>;

void Main() {
  ints(n);
  V<Vec> v(n);
  cin >> v;
  wt(BinarySearch<double>(0, 100, [&](double x) {
    DisjointSet ds(n + 2);
    int u = n, d = n + 1;
    rep(i, n) {
      double y = v[i].y;
      if (abs(100 - y) < x * 2) ds.Union(i, u);
      if (abs(y + 100) < x * 2) ds.Union(i, d);
      rep(j, i + 1, n) if ((v[j] - v[i]).Norm() < x * 2) ds.Union(i, j);
    }
    return !ds.Same(u, d);
  }));
}
