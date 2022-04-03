#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "atcoder.h"
#include "heavy_light_decomposition.h"

void Main() {
  ints(n, q);
  Graph g(n);
  V<pair<int, int>> es;
  rep(i, n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b);
    g[b].eb(a);
    es.eb(a, b);
  }

  HeavyLightDecomposition hld(g, attr_on_edge);
  update_sum::segtree t(n);
  rep(q) {
    ints(u, v, c);
    each(l, r, hld.Path(u - 1, v - 1)) t.apply(l, r, c);
  }

  each(a, b, es) wt(t.get(hld.Index(a, b)).val);
}
