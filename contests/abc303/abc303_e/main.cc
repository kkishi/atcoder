#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  V<int> deg(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].eb(v, 1);
    g[v].eb(u, 1);
    ++deg[u];
    ++deg[v];
  }
  rep(i, n) if (deg[i] == 1) {
    auto dist = Dijkstra(g, i).dist;
    V<int> ans;
    rep(j, n) if (*dist[j] % 3 == 1) ans.eb(deg[j]);
    sort(ans);
    wt(ans);
    break;
  }
}
