#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> parent(n);
  rep(i, n - 1) {
    ints(p);
    --p;
    parent[i + 1] = p;
  }
  V<int> mini(n);
  rep(i, n) mini[i] = i;
  DisjointSet ds(n);
  ints(q);
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(u, v);
      --u, --v;
      while (!ds.Same(u, v)) {
        int mu = mini[ds.Find(u)];
        int p = ds.Union(parent[u], u);
        chmin(mini[p], mu);
        u = p;
      }
    } else {
      ints(x);
      --x;
      wt(mini[ds.Find(x)] + 1);
    }
  }
}
