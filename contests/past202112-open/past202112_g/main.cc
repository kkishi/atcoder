#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  vector g(n, vector(n, false));
  rep(q) {
    ints(x, u, v);
    --u, --v;
    if (u > v) swap(u, v);
    if (x == 1) {
      g[u][v] = !g[u][v];
    } else {
      DisjointSet ds(n);
      rep(i, n) rep(j, i + 1, n) if (g[i][j]) ds.Union(i, j);
      wt(ds.Same(u, v));
    }
  }
}
