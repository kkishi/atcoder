#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  rep(i, n - 1) {
    ints(u, v, w);
    --u, --v;
    g[u].eb(v, w);
    g[v].eb(u, w);
  }
  vector<int> color(n, -1);
  Fix([&](auto dfs, int node, int parent, int dist) -> void {
    color[node] = dist % 2;
    for (auto [to, weight] : g[node]) {
      if (to == parent) continue;
      if (color[to] != -1) continue;
      dfs(to, node, dist + weight);
    }
  })(0, -1, 0);
  rep(i, n) wt(color[i]);
}
