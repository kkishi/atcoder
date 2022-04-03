#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "graph.h"
#include "heavy_light_decomposition.h"

void Main() {
  ints(n, q);
  Graph g(n);
  map<int, V<tuple<int, int, int>>> es;
  rep(n - 1) {
    ints(a, b, c, d);
    --a, --b, --c;
    g[a].eb(b);
    g[b].eb(a);
    es[c].eb(a, b, d);
  }

  VV<tuple<int, int, int, int>> qs(n);
  rep(i, q) {
    ints(x, y, u, v);
    --x, --u, --v;
    qs[x].eb(y, u, v, i);
  }

  HeavyLightDecomposition hld(g, attr_on_edge);
  AddSegmentTree<int> t0(n);
  each(_, e, es) for (auto [a, b, d] : e) t0.Set(hld.Index(a, b), d);

  AddSegmentTree<int> t1(n), t2(n);
  V<int> ans(q);
  rep(x, n) {
    for (auto [a, b, d] : es[x]) {
      t1.Set(hld.Index(a, b), d);
      t2.Set(hld.Index(a, b), 1);
    }
    for (auto [y, u, v, i] : qs[x]) {
      int sum = 0;
      each(l, r, hld.Path(u, v)) {
        sum += t0.Aggregate(l, r);
        sum -= t1.Aggregate(l, r);
        sum += t2.Aggregate(l, r) * y;
      }
      ans[i] = sum;
    }
    for (auto [a, b, d] : es[x]) {
      t1.Set(hld.Index(a, b), 0);
      t2.Set(hld.Index(a, b), 0);
    }
  }
  each(e, ans) wt(e);
}
