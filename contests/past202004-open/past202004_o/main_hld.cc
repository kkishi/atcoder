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
  Graph<int> g(n);
  for (auto [c, a, b, _] : es) {
    if (ds.Same(a, b)) continue;
    ds.Union(a, b);
    sum += c;
    g.AddEdge(a, b, c);
    g.AddEdge(b, a, c);
  }

  HeavyLightDecomposition hld(g, attr_on_edge);
  MaxSegmentTree<int> t(n);
  rep(i, n) for (const auto& e : g.Edges(i)) {
    t.Set(hld.Index(i, e.to), e.weight);
  }

  V<int> ans(m);
  for (auto [c, a, b, i] : es) {
    int ma = -big;
    each(l, r, hld.Path(a, b)) chmax(ma, t.Aggregate(l, r));
    ans[i] = sum - ma + c;
  }
  rep(i, m) wt(ans[i]);
}
