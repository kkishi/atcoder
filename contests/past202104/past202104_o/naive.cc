#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "disjoint_set.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  ints(q);
  rep(q) {
    ints(u, v);
    --u, --v;
    wt(*Dijkstra(g, u)[v]);
  }
}
