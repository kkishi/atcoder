#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"
#include "heavy_light_decomposition.h"
#include "max_segment_tree.h"

void Main() {
  ints(n, m);

  V<tuple<int, int, int, int>> es;
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    es.eb(c, a, b, i);
  }
  sort(es);

  DisjointSet ds(n);
  int sum = 0;
  Graph g(n);
  V<tuple<int, int, int>> tes;
  for (auto [c, a, b, _] : es) {
    if (ds.Same(a, b)) continue;
    ds.Union(a, b);
    sum += c;
    g[a].eb(b);
    g[b].eb(a);
    tes.eb(a, b, c);
  }

  HeavyLightDecomposition hld(g, attr_on_edge);
  MaxSegmentTree<int> t(n);
  for (auto [a, b, c] : tes) t.Set(hld.Index(a, b), c);

  V<int> ans(m);
  for (auto [c, a, b, i] : es) {
    int ma = -big;
    each(l, r, hld.Path(a, b)) chmax(ma, t.Aggregate(l, r));
    ans[i] = sum - ma + c;
  }
  rep(i, m) wt(ans[i]);
}
