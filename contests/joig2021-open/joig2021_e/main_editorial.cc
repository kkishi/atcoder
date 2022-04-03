#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, l);
  VV<tuple<int, int, bool>> g(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c, false);
    g[b].eb(a, c, true);
  }
  vector dist(m + 1, vector(n, big));
  low_priority_queue<tuple<int, int, int>> que;
  auto push = [&](int dis, int used, int node) {
    if (used <= m && chmin(dist[used][node], dis)) que.emplace(dis, used, node);
  };
  push(0, 0, 0);
  while (!que.empty()) {
    auto [dis, used, node] = que.top();
    que.pop();
    if (dis != dist[used][node]) continue;
    for (auto [to, cos, flipped] : g[node]) {
      int nused = used + flipped;
      push(dis + cos, nused, to);
    }
  }
  int ans = big;
  rep(i, m + 1) if (dist[i][n - 1] <= l) chmin(ans, i);
  if (ans == big) ans = -1;
  wt(ans);
}
