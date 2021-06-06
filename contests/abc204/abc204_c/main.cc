#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(m) {
    ints(a, b);
    g.AddEdge(a - 1, b - 1);
  }
  int ans = 0;
  rep(i, n) {
    auto d = Dijkstra(g, i);
    each(e, d) if (e)++ ans;
  }
  wt(ans);
}
