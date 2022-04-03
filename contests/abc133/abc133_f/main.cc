#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "dijkstra.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n, q);
  Graph g(n);
  WeightedGraph<int> dg(n);  // Graph with distance
  WeightedGraph<int> cg(n);  // Graph with color
  rep(n - 1) {
    ints(a, b, c, d);
    --a, --b, --c;
    g[a].eb(b);
    g[b].eb(a);
    dg[a].eb(b, d);
    dg[b].eb(a, d);
    cg[a].eb(b, c);
    cg[b].eb(a, c);
  }

  auto dist = Dijkstra(dg, 0).dist;  // Distance in the original tree
  RootedTree rt(g, 0);

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
    rep(i, sz(dg[node])) {
      auto [to, weight] = dg[node][i];
      auto [_, c] = cg[node][i];
      if (to == parent) continue;
      snap(c, node);
      if (last[c] != -1) {
        es[c].eb(last[c], node, 0);
      }
      es[c].eb(node, to, weight);
      last[c] = to;
      rec(to, node, c);
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
                       const RootedTree& rt) {
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
    Graph g(N);
    WeightedGraph<int> ng(
        N);  // Auxiliary tree with cost = 1 (can count num edges)
    WeightedGraph<int> sg(N);  // Auxiliary tree with cost = original distance
    for (auto [a, b, c] : e) {
      a = cmp(a);
      b = cmp(b);
      g[a].eb(b);
      g[b].eb(a);
      ng[a].eb(b, c != 0);
      ng[b].eb(a, c != 0);
      sg[a].eb(b, c);
      sg[b].eb(a, c);
    }

    const int r = 0;  // Any node works fine as a root.
    RootedTree rti(g, r);
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
