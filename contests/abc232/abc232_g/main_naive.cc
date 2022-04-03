#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n);
  cin >> a >> b;
  WeightedGraph<int> g(n);
  rep(i, n) rep(j, n) if (i != j) g[i].eb(j, (a[i] + b[j]) % m);
  auto res = Dijkstra(g, 0);
  rep(i, 1, n) {
    V<int> v;
    each(e, res.Path(i)) v.pb(e.to);
    dbg(i, *res.dist[i], v);
  }
  wt(*res.dist[n - 1]);
}
