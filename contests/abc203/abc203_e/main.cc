#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  map<int, V<pair<int, int>>> vs;
  rep(i, m) {
    ints(x, y);
    vs[y].eb(x, i);
  }
  each(y, v, vs) sort(all(v));
  VV<int> g(m + 1);
  each(y, v, vs) each(e, v) {
    auto [x, i] = e;
    V<int> cand = {y - 1, y + 1};
    each(c, cand) {
      if (vs.count(c) == 0) continue;
      auto& cv = vs[c];
      auto it = lower_bound(all(cv), pair<int, int>{x, 0});
      if (it == cv.begin()) continue;
      --it;
      g[it->second].pb(i);
    }
  }
  int hi = 2 * n;
  if (vs.count(n) != 0) {
    hi = vs[n][0].first - 1;
  }
  V<int> cand = {n - 1, n + 1};
  each(c, cand) {
    if (vs.count(c) == 0) continue;
    each(e, vs[c]) if (e.first <= hi + 1) g[m].pb(e.second);
  }
  int ans = 0;
  if (hi == 2 * n) ++ans;
  V<bool> visited(m + 1);
  Fix([&](auto rec, int node) -> void {
    if (visited[node]) return;
    visited[node] = true;
    each(child, g[node]) rec(child);
  })(m);
  each(y, v, vs) if (visited[v.back().second])++ ans;
  wt(ans);
}
