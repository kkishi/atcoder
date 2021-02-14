#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n);
  Graph<int> g(n);
  int root;
  rep(i, n) {
    ints(p);
    if (p == -1) {
      root = i;
    } else {
      --p;
      g.AddEdge(p, i);
    }
  }
  RootedTree t(g, root);
  ints(q);
  rep(q) {
    ints(a, b);
    --a, --b;
    wt(t.LCA(a, b) == b);
  }
}
