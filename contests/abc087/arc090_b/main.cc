#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(i, m) {
    ints(l, r, d);
    --l, --r;
    g.AddEdge(l, r, d);
    g.AddEdge(r, l, -d);
  }

  V<int> seen(n, big);
  rep(i, n) if (seen[i] == big) {
    seen[i] = 0;
    queue<pair<int, int>> que;
    que.push({i, 0});
    while (!que.empty()) {
      auto [u, p] = que.front();
      que.pop();
      for (const auto& e : g.Edges(u)) {
        int v = e.to;
        int w = p + e.weight;
        if (seen[v] != big) {
          if (seen[v] != w) {
            wt("No");
            return;
          }
          continue;
        }
        seen[v] = w;
        que.push({v, w});
      }
    }
  }
  wt("Yes");
}
