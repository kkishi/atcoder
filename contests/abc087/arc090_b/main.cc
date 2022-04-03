#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(i, m) {
    ints(l, r, d);
    --l, --r;
    g[l].eb(r, d);
    g[r].eb(l, -d);
  }

  V<int> seen(n, big);
  rep(i, n) if (seen[i] == big) {
    seen[i] = 0;
    queue<pair<int, int>> que;
    que.push({i, 0});
    while (!que.empty()) {
      auto [u, p] = que.front();
      que.pop();
      for (auto [v, w] : g[u]) {
        w += p;
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
