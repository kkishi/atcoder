#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  g.Read(m);
  auto d1 = Dijkstra(g, 0).dist;
  auto dn = Dijkstra(g, n - 1).dist;
  rep(i, n) wt(*d1[i] + *dn[i]);
}
