#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, a, b, c);
  vector d(n, vector(n, int(0)));
  cin >> d;
  WeightedGraph<int> g(n * 2);
  rep(i, n) rep(j, n) if (i != j) {
    g[i * 2].eb(j * 2, d[i][j] * a);
    rep(k, 2) g[i * 2 + k].eb(j * 2 + 1, d[i][j] * b + c);
  }
  auto dis = Dijkstra(g, 0).dist;
  wt(min(*dis[2 * n - 2], *dis[2 * n - 1]));
}
