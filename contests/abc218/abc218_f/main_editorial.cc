#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  V<pair<int, int>> es;
  rep(i, m) {
    ints(s, t);
    --s, --t;
    g.AddEdge(s, t, 1);
    es.eb(s, sz(g.Edges(s)) - 1);
  }
  auto res = Dijkstra(g, 0);
  if (!res.dist[n - 1]) {
    rep(m) wt(-1);
    return;
  }
  auto dis = [](optional<int> x) { return x ? *x : -1; };
  vector path(n, vector(n, false));
  each(e, res.Path(n - 1)) path[e.from][e.to] = true;
  each(s, i, es) {
    auto& e = g.MutableEdges(s)[i];
    if (path[s][e.to] || path[e.to][s]) {
      int to = e.to;
      e.to = e.from;
      wt(dis(Dijkstra(g, 0).dist[n - 1]));
      e.to = to;
    } else {
      wt(dis(res.dist[n - 1]));
    }
  }
}
