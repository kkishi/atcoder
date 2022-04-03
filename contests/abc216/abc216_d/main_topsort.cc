#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(i, m) {
    ints(k);
    V<int> a(k);
    cin >> a;
    rep(i, k - 1) g[a[i] - 1].eb(a[i + 1] - 1);
  }
  auto [_, ok] = TopologicalSort(g);
  wt(ok);
}
