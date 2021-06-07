#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"

void Main() {
  ints(n, m);
  VV<tuple<int, int, int>> g(n);
  rep(m) {
    ints(a, b, c, d);
    --a, --b;
    g[a].eb(b, c, d);
    g[b].eb(a, c, d);
  }

  V<int> dist(n, big);
  low_priority_queue<tuple<int, int>> que;

  auto push = [&dist, &que](int u, int c) {
    if (dist[u] <= c) return;
    dist[u] = c;
    que.push({c, u});
  };

  push(0, 0);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    if (c > dist[u]) continue;
    for (auto [v, C, D] : g[u]) {
      int y = IntSqrt(D) - (c + 1);
      if (y < 0) y = 0;
      auto f = [&](int x) { return c + x + C + D / (1 + c + x); };
      if (y > 0 && (f(y) > f(y - 1))) --y;
      if (f(y) > f(y + 1)) ++y;
      push(v, f(y));
    }
  }
  int ans = dist[n - 1];
  if (ans == big) ans = -1;
  wt(ans);
}
