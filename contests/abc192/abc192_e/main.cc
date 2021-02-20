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
  queue<int> que;
  que.push(x);
  while (!que.empty()) {
    int a = que.front();
    que.pop();
    for (auto [b, t, k] : to[a]) {
      int nd = div_ceil(dist[a], k) * k + t;
      if (chmin(dist[b], nd)) {
        que.push(b);
      }
    }
  }
  int ans = dist[y];
  if (ans == big) ans = -1;
  wt(ans);
}
