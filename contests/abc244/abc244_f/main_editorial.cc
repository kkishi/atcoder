#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector dist(n, vector(1 << n, big));
  dist[0][0] = 0;
  queue<pair<int, int>> que;
  rep(i, n) {
    dist[i][1 << i] = 1;
    que.emplace(i, 1 << i);
  }
  while (!que.empty()) {
    auto [i, mask] = que.front();
    que.pop();
    each(ni, g[i]) {
      int nmask = mask ^ (1 << ni);
      if (chmin(dist[ni][nmask], dist[i][mask] + 1)) {
        que.emplace(ni, nmask);
      }
    }
  }
  V<int> ans(1 << n, big);
  ans[0] = 0;
  rep(i, n) rep(j, 1 << n) chmin(ans[j], dist[i][j]);
  wt(accumulate(ans));
}
