#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m, t);
  vector<int> a(n);
  cin >> a;
  WeightedGraph<int> g(n), rg(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c);
    rg[b].eb(a, c);
  }
  vector<optional<int>> dist = Dijkstra(g, 0).dist;
  vector<optional<int>> rdist = Dijkstra(rg, 0).dist;
  int ans = 0;
  rep(i, n) {
    if (!dist[i] || !rdist[i]) continue;
    int rem = t - *dist[i] - *rdist[i];
    if (rem > 0) chmax(ans, rem * a[i]);
  }
  wt(ans);
}
