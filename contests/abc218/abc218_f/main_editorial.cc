#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  V<pair<int, int>> es;
  rep(i, m) {
    ints(s, t);
    --s, --t;
    g[s].eb(t, 1);
    es.eb(s, sz(g[s]) - 1);
  }
  auto res = Dijkstra(g, 0);
  if (!res.dist[n - 1]) {
    rep(m) wt(-1);
    return;
  }
  auto dis = [](optional<int> x) { return x ? *x : -1; };
  vector path(n, vector(n, false));
  V<int> p = res.Path(n - 1);
  rep(i, sz(p) - 1) path[p[i]][p[i + 1]] = true;
  each(s, i, es) {
    auto& [t, w] = g[s][i];
    if (path[s][t] || path[t][s]) {
      int to = t;
      t = s;
      wt(dis(Dijkstra(g, 0).dist[n - 1]));
      t = to;
    } else {
      wt(dis(res.dist[n - 1]));
    }
  }
}
