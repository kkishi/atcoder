#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, x, y);
  --x, --y;
  VV<tuple<int, int, int>> to(n);
  rep(m) {
    ints(a, b, t, k);
    --a, --b;
    to[a].eb(b, t, k);
    to[b].eb(a, t, k);
  }
  V<int> dist(n, big);
  dist[x] = 0;
  low_priority_queue<pair<int, int>> que;
  que.emplace(0, x);
  while (!que.empty()) {
    auto [d, a] = que.top();
    que.pop();
    if (d > dist[a]) continue;
    for (auto [b, t, k] : to[a]) {
      if (chmin(dist[b], div_ceil(dist[a], k) * k + t)) {
        que.emplace(dist[b], b);
      }
    }
  }
  int ans = dist[y];
  if (ans == big) ans = -1;
  wt(ans);
}
