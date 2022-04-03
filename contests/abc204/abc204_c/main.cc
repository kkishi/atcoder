#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(a, b);
    g[a - 1].eb(b - 1, 1);
  }
  int ans = 0;
  rep(i, n) each(e, Dijkstra(g, i).dist) if (e)++ ans;
  wt(ans);
}
