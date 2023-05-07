#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].eb(v, 1);
    g[v].eb(u, 1);
  }
  ints(k);
  V<int> white(n);
  V<pair<int, int>> pd;
  rep(k) {
    ints(p, d);
    --p;
    pd.eb(p, d);
    auto dist = Dijkstra(g, p).dist;
    rep(i, n) {
      assert(dist[i]);
      if (dist[i] < d) white[i] = true;
    }
  }
  bool ok = true;
  each(p, d, pd) {
    auto dist = Dijkstra(g, p).dist;
    bool ok2 = false;
    rep(i, n) {
      assert(dist[i]);
      if (dist[i] == d && !white[i]) ok2 = true;
    }
    if (!ok2) ok = false;
  }
  wt(ok);
  if (ok) {
    string ans(n, '0');
    rep(i, n) if (!white[i]) ans[i] = '1';
    wt(ans);
  }
}
