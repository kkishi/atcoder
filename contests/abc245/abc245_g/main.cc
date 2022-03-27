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
  V<int> cnt(n);
  vector dist(2, vector(n, big));
  vector cntr(2, vector(n, big));
  low_priority_queue<tuple<int, int, int>> que;
  each(e, b) que.emplace(0, e, a[e]);
  while (!que.empty()) {
    auto [cost, node, country] = que.top();
    que.pop();
    int& c = cnt[node];
    if (c == 2) continue;
    if (c == 1 && cntr[0][node] == country) continue;
    dist[c][node] = cost;
    cntr[c][node] = country;
    ++c;
    each(nnode, weight, g[node]) que.emplace(cost + weight, nnode, country);
  }
  V<int> x(n);
  rep(i, n) {
    int mi = big;
    rep(j, 2) if (cntr[j][i] != a[i]) chmin(mi, dist[j][i]);
    if (mi == big) mi = -1;
    x[i] = mi;
  }
  wt(x);
}
