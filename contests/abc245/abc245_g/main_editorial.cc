#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k, l);
  V<int> a(n), b(l);
  cin >> a >> b;
  each(e, a)-- e;
  each(e, b)-- e;
  VV<pair<int, int>> g(n);
  rep(m) {
    ints(u, v, c);
    --u, --v;
    g[u].eb(v, c);
    g[v].eb(u, c);
  }
  V<int> x(n, big);
  for (int i = 0; (1 << i) < k; ++i) {
    rep(group, 2) {
      vector dist(n, big);
      low_priority_queue<tuple<int, int>> que;
      each(e, b) if (hasbit(a[e], i) == group) que.emplace(0, e);
      while (!que.empty()) {
        auto [cost, node] = que.top();
        que.pop();
        if (cost > dist[node]) continue;
        each(nnode, weight, g[node]) if (chmin(dist[nnode], cost + weight)) {
          que.emplace(cost + weight, nnode);
        }
      }
      rep(j, n) if (hasbit(a[j], i) != group) chmin(x[j], dist[j]);
    }
  }
  each(e, x) if (e == big) e = -1;
  wt(x);
}
