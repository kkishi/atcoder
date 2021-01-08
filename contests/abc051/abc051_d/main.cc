#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<tuple<int, int, int>> e(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    e[a].pb({b, c, i});
    e[b].pb({a, c, i});
  }
  V<bool> used(m);
  rep(i, n) {
    V<int> dist(n, big);
    dist[i] = 0;
    low_priority_queue<tuple<int, int, int>> que;
    que.push({0, i, -1});
    while (!que.empty()) {
      auto [distance, node, edge_index] = que.top();
      que.pop();
      if (distance > dist[node]) continue;
      dist[node] = distance;
      if (edge_index >= 0) {
        used[edge_index] = true;
      }
      for (auto [n_node, cost, n_edge_index] : e[node]) {
        que.push({distance + cost, n_node, n_edge_index});
      }
    }
  }
  wt(count(all(used), false));
}
