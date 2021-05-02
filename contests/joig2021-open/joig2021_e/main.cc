#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, l);
  Graph<tuple<int, bool>> g(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    g.AddEdge(a, b, {c, false});
    g.AddEdge(b, a, {c, true});
  }
  vector dist(m + 1, vector(n, big));
  low_priority_queue<tuple<int, int, int>> que;
  auto push = [&](int dis, int used, int node) {
    rep(i, used) if (dist[i][node] <= dis) return;
    if (chmin(dist[used][node], dis)) que.emplace(dis, used, node);
  };
  push(0, 0, 0);
  while (!que.empty()) {
    auto [dis, used, node] = que.top();
    que.pop();
    if (dis > dist[used][node]) continue;
    each(e, g.Edges(node)) {
      auto [cos, flipped] = e.weight;
      int nused = used;
      if (flipped) ++nused;
      push(dis + cos, nused, e.to);
    }
  }
  int ans = big;
  rep(i, m + 1) if (dist[i][n - 1] <= l) chmin(ans, i);
  if (ans == big) ans = -1;
  wt(ans);
}
