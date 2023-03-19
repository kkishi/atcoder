#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "graph.h"
#include "heavy_light_decomposition.h"

void Main() {
  ints(n);
  V<tuple<int, int, int>> es;
  Graph g(n);
  rep(n - 1) {
    ints(u, v, w);
    --u, --v;
    es.eb(u, v, w);
    g[u].eb(v);
    g[v].eb(u);
  }

  HeavyLightDecomposition hld(g, attr_on_edge);
  AddSegmentTree<int> t(n);
  for (auto [u, v, w] : es) t.Set(hld.Index(u, v), w);

  ints(q);
  rep(q) {
    ints(tp);
    if (tp == 1) {
      ints(i, w);
      --i;
      auto [u, v, _] = es[i];
      t.Set(hld.Index(u, v), w);
    } else {
      ints(u, v);
      --u, --v;
      int ans = 0;
      each(l, r, hld.Path(u, v)) ans += t.Aggregate(l, r);
      wt(ans);
    }
  }
}
