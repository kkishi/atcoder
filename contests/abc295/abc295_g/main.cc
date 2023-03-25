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
  V<int> root(n);
  V<int> mini(n);
  rep(i, n) {
    root[i] = i;
    mini[i] = i;
  }
  DisjointSet ds(n);
  auto findRoot = [&](int i) { return root[ds.Find(i)]; };
  auto findMini = [&](int i) { return mini[ds.Find(i)]; };
  auto merge = [&](int parent, int child) {
    int p = ds.Find(parent);
    int c = ds.Find(child);
    ds.Union(parent, child);
    int i = ds.Find(parent);
    root[i] = root[p];
    mini[i] = min(mini[p], mini[c]);
  };
  ints(q);
  rep(q) {
    ints(kind);
    if (kind == 1) {
      ints(u, v);
      --u, --v;
      while (!ds.Same(u, v)) {
        int p = findRoot(parent[u]);
        merge(p, u);
        u = p;
      }
    } else {
      ints(x);
      --x;
      wt(findMini(x) + 1);
    }
  }
}
