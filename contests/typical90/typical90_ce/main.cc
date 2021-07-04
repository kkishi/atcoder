#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> g(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  V<bool> hi(n);
  rep(i, n) hi[i] = sz(g[i]) * sz(g[i]) > n;
  VV<int> G(n);
  rep(i, n) each(e, g[i]) if (hi[e]) G[i].pb(e);
  V<tuple<int, int>> eager(n), lazy(n);
  ints(q);
  rep(i, q) {
    ints(x, y);
    --x, --y;
    tuple<int, int> c = eager[x];
    eager[x] = {i + 1, y};
    lazy[x] = {i + 1, y};
    each(e, G[x]) chmax(c, lazy[e]);
    if (!hi[x]) each(e, g[x]) eager[e] = {i + 1, y};
    wt(get<1>(c) + 1);
  }
}
