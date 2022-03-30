#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "rand.h"

void Main() {
  int n = 10;
  V<tuple<int, int, int>> es;
  Rand r;
  DisjointSet ds(n);
  int C = 100;
  rep(i, n) rep(j, i + 1, n) if (r.Int(0, 1)) {
    es.eb(i, j, r.Int(1, C));
    ds.Union(i, j);
  }
  while (ds.Size(0) != n) {
    int a = r.Int(0, n - 1);
    int b = r.Int(0, n - 1);
    int c = r.Int(1, C);
    if (!ds.Same(a, b)) {
      ds.Union(a, b);
      es.eb(a, b, c);
    }
  }

  wt(n, sz(es));
  for (auto [a, b, c] : es) {
    wt(a + 1, b + 1, c);
  }
}
