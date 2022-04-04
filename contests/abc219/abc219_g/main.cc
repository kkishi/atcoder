#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, q);
  Graph g(n);
  g.Read(m);
  V<bool> hi(n);
  rep(i, n) hi[i] = sz(g[i]) * sz(g[i]) > n;
  VV<int> G(n);
  rep(i, n) each(e, g[i]) if (hi[e]) G[i].pb(e);
  V<tuple<int, int>> eager(n), lazy(n);
  rep(i, n) {
    eager[i] = {-1, i + 1};
    lazy[i] = {-2, i + 1};
  }
  rep(i, q) {
    ints(x);
    --x;
    tuple<int, int> c = eager[x];
    each(e, G[x]) chmax(c, lazy[e]);
    int y = get<1>(c);
    eager[x] = {i + 1, y};
    lazy[x] = {i + 1, y};
    if (!hi[x]) each(e, g[x]) eager[e] = {i + 1, y};
  }
  V<int> ans(n);
  rep(i, n) {
    int x = i;
    tuple<int, int> c = eager[x];
    each(e, G[x]) chmax(c, lazy[e]);
    ans[i] = get<1>(c);
  }
  wt(ans);
}
