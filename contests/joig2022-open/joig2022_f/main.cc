#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, q, l);
  WeightedGraph<int> g(n);
  g.Read(m);
  vector dist(n, vector(30, big));
  low_priority_queue<tuple<int, int, int>> que;
  dist[0][0] = 1;
  que.emplace(1, 0, 0);
  while (!que.empty()) {
    auto [dis, node, blue] = que.top();
    que.pop();
    each(nnode, c, g[node]) {
      int ndis = dis;
      int nblue = blue;
      if (c == 2) ++nblue;
      ndis += 1 << blue;
      if (ndis > l) continue;
      if (chmin(dist[nnode][nblue], ndis)) {
        que.emplace(ndis, nnode, nblue);
      }
    }
  }
  rep(q) {
    ints(t);
    int ans = min(dist[t - 1]);
    if (ans == big) {
      wt("Large");
    } else {
      wt(ans);
    }
  }
}
