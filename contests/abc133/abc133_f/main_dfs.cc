#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n, q);
  Graph<int> dg(n);  // Graph with distance
  Graph<int> cg(n);  // Graph with color
  rep(n - 1) {
    ints(a, b, c, d);
    --a, --b, --c;
    dg.AddEdge(a, b, d);
    dg.AddEdge(b, a, d);
    cg.AddEdge(a, b, c);
    cg.AddEdge(b, a, c);
  }

  auto dist = Dijkstra(dg, 0).dist;  // Distance in the original tree
  RootedTree<int> rt(dg, 0);

  V<int> ans(q);
  VV<pair<int, int>> query_lca(n);
  VV<pair<int, int>> query_to(n);
  V<int> ys;
  rep(i, q) {
    ints(x, y, u, v);
    --x, --u, --v;
    ys.eb(y);
    int lca = rt.LCA(u, v);
    ans[i] = *dist[u] + *dist[v] - *dist[lca] * 2;
    query_to[u].eb(x, i);
    query_to[v].eb(x, i);
    query_lca[lca].eb(x, i);
  }

  V<int> num(n);
  V<int> sum(n);
  Fix([&](auto rec, int node, int parent) -> void {
    each(x, i, query_to[node]) {
      ans[i] -= sum[x];
      ans[i] += num[x] * ys[i];
    }
    each(x, i, query_lca[node]) {
      ans[i] += sum[x] * 2;
      ans[i] -= num[x] * ys[i] * 2;
    }
    rep(i, sz(dg.Edges(node))) {
      const auto& de = dg.Edges(node)[i];
      const auto& ce = cg.Edges(node)[i];
      if (de.to == parent) continue;
      int c = ce.weight;
      int d = de.weight;
      ++num[c];
      sum[c] += d;
      rec(ce.to, node);
      sum[c] -= d;
      --num[c];
    }
  })(0, -1);

  each(e, ans) wt(e);
}
