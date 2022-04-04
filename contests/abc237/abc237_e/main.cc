#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<int> h(n);
  cin >> h;
  Graph g(n);
  g.Read(m);
  vector dist(n, -big);
  dist[0] = 0;
  priority_queue<pair<int, int>> L, H;
  L.emplace(0, 0);
  while (true) {
    auto& que = !L.empty() ? L : H;
    if (que.empty()) break;
    auto [d, node] = que.top();
    que.pop();
    if (dist[node] > d) continue;
    auto push = [&](auto& que, int d, int n) {
      if (chmax(dist[n], d)) {
        que.emplace(d, n);
      }
    };
    each(e, g[node]) {
      int dh = abs(h[e] - h[node]);
      if (h[e] <= h[node]) {
        push(L, dist[node] + dh, e);
      } else {
        push(H, dist[node] - dh * 2, e);
      }
    }
  }
  wt(max(dist));
}
