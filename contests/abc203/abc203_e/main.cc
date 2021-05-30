#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  map<int, V<pair<int, int>>> vs;
  rep(i, m) {
    ints(x, y);
    if (x == 0 && y == n) continue;
    vs[y].eb(x, i);
  }
  each(y, v, vs) sort(all(v));
  VV<int> g(m + 1);
  DisjointSet ds(m + 1);
  each(y, v, vs) each(e, v) {
    auto [x, i] = e;
    V<int> cand = {y - 1, y + 1};
    each(c, cand) {
      if (vs.count(c) == 0) continue;
      auto& cv = vs[c];
      auto it = lower_bound(all(cv), pair<int, int>{x, 0});
      if (it == cv.begin()) continue;
      --it;
      ds.Union(it->second, i);
      dbg("Union", it->second, i);
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
    each(e, vs[c]) if (0 < e.first && e.first <= hi + 1) {
      dbg("Union_root", e.second);
      ds.Union(e.second, m);
      g[m].pb(e.second);
    }
  }
  int ans = 0;
  if (hi == 2 * n) ++ans;
  dbg(ans);
  /*
  each(y, v, vs) if (ds.Same(v.back().second, m)) {
    dbg("ans", v.back().second);
    ++ans;
  }
  */
  V<bool> visited(m + 1);
  Fix([&](auto rec, int node) -> void {
    if (visited[node]) return;
    dbg("rec", node);
    visited[node] = true;
    each(child, g[node]) rec(child);
  })(m);
  each(y, v, vs) if (visited[v.back().second]) {
    dbg("ans", v.back().second);
    ++ans;
  }
  wt(ans);
}
