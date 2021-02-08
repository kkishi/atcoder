
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

  LCA lca(g);

  V<int> parent_edge(n);
  Fix([&](auto rec, int node, int parent) -> void {
    auto& edges = g.Edges(node);
    rep(i, sz(edges)) {
      int child = edges[i].to;
      if (child == parent) continue;
      parent_edge[child] = i;
      rec(child, node);
    }
  })(0, -1);

  V<tuple<int, int, int>> queries;
  rep(q) {
    ints(u, v, c);
    queries.eb(u, v, c);
  }
  reverse(all(queries));

  DisjointSet ds(n);
  V<int> roots(n);
  iota(all(roots), int(0));

  V<int> ans(n - 1);
  for (auto [u, v, c] : queries) {
    --u, --v;
    auto paint = [&](int ancestor, int child) {
      while (lca.Depth(child) > lca.Depth(ancestor)) {
        int parent = lca.Parent(child);
        if (ds.Same(child, parent)) {
          child = roots[ds.Find(child)];
          continue;
        }
        ans[g.Edges(parent)[parent_edge[child]].weight] = c;
        int r = roots[ds.Find(parent)];
        ds.Union(child, parent);
        roots[ds.Find(child)] = r;
        child = r;
      }
    };
    int p = lca.Of(u, v);
    paint(p, u);
    paint(p, v);
  }
  each(a, ans) wt(a);
}
