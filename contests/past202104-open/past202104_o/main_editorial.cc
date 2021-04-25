#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "disjoint_set.h"
#include "graph.h"
#include "lca.h"

bool Update(map<int, int>& m, int k, int v) {
  auto [it, ok] = m.emplace(k, v);
  if (ok) return true;
  if (it->second <= v) return false;
  it->second = v;
  return true;
}

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  Graph<int> tree(n);      // Spanning tree. Any one is fine.
  VV<int> extra_edges(n);  // Extra edges not needed for the spanning tree.
  set<int> extra_nodes;    // Nodes appear in the extra edges.
  rep(m) {
    ints(a, b);
    --a, --b;
    if (ds.Same(a, b)) {
      extra_edges[a].pb(b);
      extra_edges[b].pb(a);
      extra_nodes.insert(a);
      extra_nodes.insert(b);
    } else {
      ds.Union(a, b);
      tree.AddEdge(a, b, 1);
      tree.AddEdge(b, a, 1);
    }
  }
  RootedTree rt(tree, 0);
  V<optional<int>> rd = Dijkstra(tree, 0);
  ints(q);
  rep(q) {
    ints(u, v);
    --u, --v;
    set<int> cand = extra_nodes;
    cand.insert(u);
    cand.insert(v);
    map<int, int> dist;
    low_priority_queue<pair<int, int>> que;
    auto push = [&](int n, int d) {
      if (Update(dist, n, d)) que.emplace(d, n);
    };
    push(u, 0);
    while (!que.empty()) {
      auto [d, n] = que.top();
      que.pop();
      if (d > dist[n]) continue;
      each(c, extra_edges[n]) push(c, d + 1);
      each(c, cand) {
        int nd = d + *rd[n] + *rd[c] - *rd[rt.LCA(n, c)] * 2;
        push(c, nd);
      }
    }
    wt(dist[v]);
  }
}
