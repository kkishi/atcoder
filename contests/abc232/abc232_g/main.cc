#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n);
  cin >> a >> b;
  set<pair<int, int>> st;
  rep(i, 1, n) st.emplace(b[i], i);
  vector dist(n, big);
  dist[0] = 0;
  low_priority_queue<tuple<int, int, int>> que;
  auto next = [&](int node) {
    if (st.empty()) return;
    auto it = st.lower_bound({m - a[node], -1});
    if (it == st.end()) it = st.begin();
    int nd = dist[node] + (a[node] + it->first) % m;
    int nnode = it->second;
    if (chmin(dist[nnode], nd)) que.emplace(nd, node, nnode);
  };
  next(0);
  while (!que.empty()) {
    auto [_, from, to] = que.top();
    que.pop();
    if (st.erase({b[to], to})) next(to);
    next(from);
  }
  wt(dist[n - 1]);
}
