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
  V<bool> seen(n);
  low_priority_queue<tuple<int, int, int>> que;
  seen[0] = true;
  each(i, w, g[0]) que.emplace(w, 0, i);
  V<int> ans;
  while (!que.empty()) {
    auto [w, f, t] = que.top();
    que.pop();
    if (seen[t]) continue;
    seen[t] = true;
    ans.eb(idx[{f, t}]);
    each(nt, nw, g[t]) que.emplace(w + nw, t, nt);
  }
  wt(ans);
}
