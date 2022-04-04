#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();

  RootedTree t(g);
  ints(q);
  rep(q) {
    ints(a, b);
    --a, --b;
    int c = t.LCA(a, b);
    wt(t.Depth(a) + t.Depth(b) - t.Depth(c) * 2 + 1);
  }
}
