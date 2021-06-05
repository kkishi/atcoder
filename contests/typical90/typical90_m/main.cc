#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g.AddEdge(a, b, c);
    g.AddEdge(b, a, c);
  }
  auto d1 = Dijkstra(g, 0);
  auto dn = Dijkstra(g, n - 1);
  rep(i, n) wt(*d1[i] + *dn[i]);
}
