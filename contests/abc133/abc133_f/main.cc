#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

struct Weight {
  int color, length;
};

void Main() {
  ints(n, q);
  Graph<Weight> g(n);
  rep(i, n - 1) {
    ints(a, b, c, d);
    --a, --b;
    g.AddEdge(a, b, {c, d});
    g.AddEdge(b, a, {c, d});
  }
  vector<int> ins(n), outs(n);
  vector<int> depths;
  Fix([&](auto dfs, int node, int parent, int depth) -> void {
    int index = depths.size();
    ins[node] = index;
    depths.push_back(depth);
    for (const auto& e : g.Edges(node)) {
      if (e.to == parent) continue;
      dfs(e.to, node, depth + 1);
    }
  })(0, -1, 0);
}
