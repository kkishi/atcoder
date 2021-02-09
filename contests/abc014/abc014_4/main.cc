#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(N);
  Graph<int> g(N);
  rep(N - 1) {
    ints(x, y);
    --x, --y;
    g.AddEdge(x, y);
    g.AddEdge(y, x);
  }

  RootedTree t(g);
  ints(q);
  rep(q) {
    ints(a, b);
    --a, --b;
    int c = t.LCA(a, b);
    wt(t.Depth(a) + t.Depth(b) - t.Depth(c) * 2 + 1);
  }
}
