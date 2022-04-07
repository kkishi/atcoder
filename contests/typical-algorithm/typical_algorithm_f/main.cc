#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "kruskal.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(u, v, c);
    g[u].eb(v, c);
    g[v].eb(u, c);
  }
  wt(Kruskal(g));
}
