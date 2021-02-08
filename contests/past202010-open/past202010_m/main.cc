#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "graph.h"

void Main() {
  ints(n, q);
  Graph<int> g(n);
  rep(i, n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, i);
    g.AddEdge(b, a, i);
  }

  // Compute a table for LCA
  const int M = 17;
  vector parents(M, V<int>(n));
  V<int> parent_edge(n);
  V<int> depths(n);
  Fix([&](auto rec, int node, int parent, int depth) -> void {
    depths[node] = depth;
    auto& edges = g.Edges(node);
    rep(i, sz(edges)) {
      int child = edges[i].to;
      if (child == parent) continue;
      parents[0][child] = node;
      parent_edge[child] = i;
      rec(child, node, depth + 1);
    }
  })(0, -1, 0);
  rep(i, 1, M) rep(j, n) parents[i][j] = parents[i - 1][parents[i - 1][j]];

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
    if (depths[u] > depths[v]) swap(u, v);
    int U = u, V = v;
    rrep(i, M) if (depths[V] - (1 << i) >= depths[U]) V = parents[i][V];

    auto paint = [&](int ancestor, int child) {
      while (depths[child] > depths[ancestor]) {
        int parent = parents[0][child];
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
    if (U == V) {
      paint(u, v);
    } else {
      rrep(i, M) if (int PU = parents[i][U], PV = parents[i][V]; PU != PV) {
        U = PU;
        V = PV;
      }
      int P = parents[0][U];
      assert(P == parents[0][V]);
      paint(P, u);
      paint(P, v);
    }
  }
  each(a, ans) wt(a);
}
