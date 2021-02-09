#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n, q);
  Graph<int> g(n);
  rep(i, n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, i);
    g.AddEdge(b, a, i);
  }

  V<tuple<int, int, int>> queries;
  rep(q) {
    ints(u, v, c);
    queries.eb(u - 1, v - 1, c);
  }
  reverse(all(queries));

  V<int> ans(n - 1);

  RootedTree tree(g);
  DisjointSet ds(n);
  V<int> roots(n);
  iota(all(roots), int(0));

  for (auto [u, v, c] : queries) {
    auto paint = [&](int ancestor, int child) {
      while (tree.Depth(child) > tree.Depth(ancestor)) {
        auto& e = tree.AscendingEdge(child);
        int parent = e.to;
        if (ds.Same(child, parent)) {
          child = roots[ds.Find(child)];
          continue;
        }
        ans[e.weight] = c;
        int r = roots[ds.Find(parent)];
        ds.Union(child, parent);
        roots[ds.Find(child)] = r;
        child = r;
      }
    };
    int p = tree.LCA(u, v);
    paint(p, u);
    paint(p, v);
  }
  each(a, ans) wt(a);
}
