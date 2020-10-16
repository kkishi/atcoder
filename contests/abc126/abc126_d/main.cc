#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph<int> g(n);
  rep(i, n - 1) {
    ints(u, v, w);
    --u, --v;
    g.AddEdge(u, v, w);
    g.AddEdge(v, u, w);
  }
  vector<int> color(n, -1);
  Fix([&](auto dfs, int node, int parent, int dist) -> void {
    color[node] = dist % 2;
    for (const auto& e : g.Edges(node)) {
      if (e.to == parent) continue;
      if (color[e.to] != -1) continue;
      dfs(e.to, node, dist + e.weight);
    }
  })(0, -1, 0);
  rep(i, n) wt(color[i]);
}
