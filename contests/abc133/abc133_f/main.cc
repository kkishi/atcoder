#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
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

  VV<int> cs(n);  // Queried colors for the node
  VV<tuple<int, int, int, int>> qs(n);
  rep(i, q) {
    ints(x, y, u, v);
    --x, --u, --v;
    qs[x].eb(y, u, v, i);
    cs[u].pb(x);
    cs[v].pb(x);
  }

  // es[color] = edges of the auxiliary tree consisting of the edges in the
  // original tree with that color.
  VV<tuple<int, int, int>> es(n);
  V<int> last(n, -1);
  VV<int> to_be_snapped(n);
  map<pair<int, int>, int> snapped;  // Nearest node in the auxiliary tree.
  auto snap = [&](int color, int node) {
    each(e, to_be_snapped[color]) snapped[{color, e}] = node;
    to_be_snapped[color].clear();
  };

  Fix([&](auto rec, int node, int parent, int color) -> void {
    each(e, cs[node]) to_be_snapped[e].eb(node);
    rep(i, sz(dg.Edges(node))) {
      const auto& de = dg.Edges(node)[i];
      const auto& ce = cg.Edges(node)[i];
      if (de.to == parent) continue;
      int c = ce.weight;
      snap(c, node);
      if (last[c] != -1) {
        es[c].eb(last[c], node, 0);
      }
      es[c].eb(node, de.to, de.weight);
      last[c] = de.to;
      rec(de.to, node, c);
      last[c] = node;
    }
    if (parent != -1) snap(color, node);
  })(0, -1, -1);

  rep(color, n) if (last[color] != -1) snap(color, last[color]);

  each(e, es) {
    // Eliminate redundant edges from e to make it a canonical tree form.
    V<tuple<int, int, int>> E;
    set<int> seen;
    for (auto [a, b, c] : e) {
      if (a == b) continue;
      bool aok = seen.insert(a).second;
      bool bok = seen.insert(b).second;
      if (!aok && !bok) continue;
      E.eb(a, b, c);
    }
    swap(e, E);
  }

  V<int> ans(q);
  rep(x, n) {
    auto distance = [](int u, int v, const V<optional<int>>& d,
                       const RootedTree<int>& rt) {
      int lca = rt.LCA(u, v);
      return *d[u] + *d[v] - *d[lca] * 2;
    };
    for (auto [y, u, v, i] : qs[x]) {
      ans[i] = distance(u, v, dist, rt);
    }
    const auto& e = es[x];
    if (e.empty()) continue;  // There's no edges with color x, so no adjustment

    V<int> v;
    for (auto [a, b, _] : e) {
      v.eb(a);
      v.eb(b);
    }
    Compressor cmp(v);
    int N = sz(cmp.coord);
    Graph<int> ng(N);  // Auxiliary tree with cost = 1 (can count num edges)
    Graph<int> sg(N);  // Auxiliary tree with cost = original distance
    for (auto [a, b, c] : e) {
      a = cmp(a);
      b = cmp(b);
      ng.AddEdge(a, b, c != 0);
      ng.AddEdge(b, a, c != 0);
      sg.AddEdge(a, b, c);
      sg.AddEdge(b, a, c);
    }

    const int r = 0;  // Any node works fine as a root.
    RootedTree<int> rti(ng, r);
    auto num_edges = Dijkstra(ng, r).dist;
    auto sum_edges = Dijkstra(sg, r).dist;

    for (auto [y, u, v, i] : qs[x]) {
      assert(snapped.count({x, u}));
      assert(snapped.count({x, v}));
      int U = snapped[{x, u}];
      int V = snapped[{x, v}];
      int ne = distance(cmp(U), cmp(V), num_edges, rti);
      int se = distance(cmp(U), cmp(V), sum_edges, rti);
      ans[i] += -se + ne * y;
    }
  }
  each(e, ans) wt(e);
}
