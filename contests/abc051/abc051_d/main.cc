#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  VV<tuple<int, int, int>> e(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    e[a].push_back({b, c, i});
    e[b].push_back({a, c, i});
  }
  V<bool> used(m);
  rep(i, n) {
    int inf = numeric_limits<int>::max() / 10;
    V<int> dist(n, inf);
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
