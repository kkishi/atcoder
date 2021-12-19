#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(n);
  cin >> a >> b;
  set<pair<int, int>> st;
  rep(i, n) st.emplace(b[i], i);
  low_priority_queue<tuple<int, int, int>> que;
  vector dist(n, big);
  dist[0] = 0;
  que.emplace(0, -1, 0);
  while (!que.empty()) {
    auto [_, from, to] = que.top();
    que.pop();
    auto next = [&](int node) {
      if (st.empty()) return;
      int x = m - a[node];
      auto it = st.lower_bound({x, -1});
      if (it == st.end()) it = st.begin();
      int nd = dist[node] + (a[node] + it->first) % m;
      int nnode = it->second;
      if (chmin(dist[nnode], nd)) {
        que.emplace(nd, node, nnode);
      }
    };
    auto it = st.lower_bound({b[to], to});
    if (it != st.end() && it->second == to) {
      st.erase(it);
      next(to);
      if (from != -1) next(from);
    } else {
      next(from);
    }
  }
  wt(dist[n - 1]);
}
