#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  V<tuple<int, int, int>> e;
  map<pair<int, int>, int> idx;
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    e.eb(a, b, c);
    idx[{a, b}] = idx[{b, a}] = i + 1;
  }
  WeightedGraph<int> g(n);
  for (auto [a, b, c] : e) {
    g[a].eb(b, c);
    g[b].eb(a, c);
  }
  V<int> dist(n, big);
  low_priority_queue<tuple<int, int>> que;
  dist[0] = 0;
  que.emplace(0, 0);
  V<int> ans(n - 1);
  while (!que.empty()) {
    auto [d, n] = que.top();
    que.pop();
    if (dist[n] < d) continue;
    each(c, w, g[n]) {
      if (chmin(dist[c], d + w)) {
        ans[c - 1] = idx[{n, c}];
        que.emplace(d + w, c);
      }
    }
  }
  wt(ans);
}
