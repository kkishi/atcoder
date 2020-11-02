#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(N);
  Graph<int> g(N);
  rep(N - 1) {
    ints(x, y);
    --x, --y;
    g.AddEdge(x, y);
    g.AddEdge(y, x);
  }

  VV<int> parent(30, V<int>(N));
  V<int> dist(N);
  Fix([&](auto rec, int n, int p, int d) -> void {
    dist[n] = d;
    for (const auto& e : g.Edges(n)) {
      if (e.to == p) continue;
      parent[0][e.to] = n;
      rec(e.to, n, d + 1);
    }
  })(0, -1, 0);
  rep(i, 1, 30) rep(j, N) parent[i][j] = parent[i - 1][parent[i - 1][j]];

  auto lca = [&](int a, int b) {
    if (dist[a] > dist[b]) swap(a, b);
    int d = dist[b] - dist[a];
    rep(i, 30) if ((d >> i) & 1) b = parent[i][b];
    if (a == b) return a;
    rrep(i, 30) if (int pa = parent[i][a], pb = parent[i][b]; pa != pb) {
      a = pa, b = pb;
    }
    return parent[0][a];
  };

  ints(q);
  rep(q) {
    ints(a, b);
    --a, --b;
    wt(dist[a] + dist[b] - dist[lca(a, b)] * 2 + 1);
  }
}
