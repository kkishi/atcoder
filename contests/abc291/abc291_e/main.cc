#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

pair<V<int>, bool> Solve() {
  ints(n, m);
  V<int> x(m), y(m);
  Graph g(n);
  V<int> deg(n);
  rep(i, m) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
    g[x[i]].eb(y[i]);
    ++deg[y[i]];
  }
  queue<int> que;
  V<int> ans;
  rep(i, n) {
    if (deg[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    if (que.size() != 1) {
      return {{}, false};
    }
    int node = que.front();
    que.pop();
    ans.pb(node);
    each(child, g[node]) {
      --deg[child];
      if (deg[child] == 0) {
        que.push(child);
      }
    }
  }
  return {ans, sz(ans) == n};
}

void Main() {
  auto [ans, ok] = Solve();
  wt(ok);
  if (ok) {
    int n = sz(ans);
    V<int> idx(n);
    rep(i, n) idx[ans[i]] = i + 1;
    wt(idx);
  }
}
