#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "atcoder.h"
#include "graph.h"
#include "heavy_light_decomposition.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  V<pair<int, int>> es;
  rep(n - 1) {
    ints(p, q);
    --p, --q;
    g.AddEdge(p, q);
    g.AddEdge(q, p);
    es.eb(p, q);
  }
  HeavyLightDecomposition hld(g, attr_on_edge);
  AddSegmentTree<int> up(n), down(n);
  rep(i, 1, n) {
    up.Set(i, 1);
    down.Set(i, 1);
  }
  rep(m) {
    rd(char, c);
    if (c == 'I') {
      ints(r, s, t);
      --r;
      auto [p, q] = es[r];
      if (p > q) {
        swap(s, t);
      }
      if (hld.Parent(q) == p) {
        swap(s, t);
      }
      up.Set(hld.Index(p, q), s);
      down.Set(hld.Index(p, q), t);
    } else {
      ints(x, y);
      --x, --y;
      int z = hld.LCA(x, y);
      int ans = 0;
      each(l, r, hld.Path(x, z)) ans += up.Aggregate(l, r);
      each(l, r, hld.Path(z, y)) ans += down.Aggregate(l, r);
      wt(ans);
    }
  }
}
