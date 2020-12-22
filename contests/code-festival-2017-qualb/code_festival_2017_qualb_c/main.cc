#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> to(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  V<bool> visited_odd(n);
  V<bool> visited_even(n);
  stack<pair<int, int>> stk;
  stk.push({0, 0});
  while (!stk.empty()) {
    auto [node, dist_parity] = stk.top();
    stk.pop();
    V<bool>& visited = dist_parity ? visited_odd : visited_even;
    if (visited[node]) continue;
    visited[node] = true;
    for (int child : to[node]) {
      stk.push({child, 1 - dist_parity});
    }
  }
  auto nC2 = [](int n) { return n * (n - 1) / 2; };
  int ans = nC2(n) - m;
  int cnt = 0;
  rep(i, n) if (visited_even[i] && !visited_odd[i])++ cnt;
  if (cnt > 0) {
    ans -= nC2(cnt) + nC2(n - cnt);
  }
  wt(ans);
}
