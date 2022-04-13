#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "disjoint_set.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> bomb(n), cord(m);
  cin >> bomb >> cord;
  V<int> v;
  each(a, _, bomb) v.eb(a);
  Compressor c(v);
  each(a, _, bomb) a = c(a);
  each(l, r, cord) {
    l = c(l);
    r = c(r + 1);
  }

  int N = sz(c.coord);

  unordered_map<int, int> idx;
  auto pack = [](int i, int j) { return (i << 32) | j; };
  rep(i, m) {
    auto [l, r] = cord[i];
    idx[pack(l, r)] = idx[pack(r, l)] = i;
  }

  DisjointSet ds(N + 1);
  each(l, r, cord) ds.Union(l, r);

  map<int, V<int>> groups;
  rep(i, N + 1) groups[ds.Find(i)].eb(i);

  map<int, Compressor*> compressors;
  map<int, Graph> graphs;
  map<int, DisjointSet*> disjoint_sets;
  each(root, group, groups) {
    compressors[root] = new Compressor(group);
    graphs[root] = Graph(sz(group));
    disjoint_sets[root] = new DisjointSet(sz(group));
  }

  each(l, r, cord) {
    int root = ds.Find(l);
    const auto& c = *compressors[root];
    int L = c(l), R = c(r);
    if (disjoint_sets[root]->Union(L, R)) {
      auto& g = graphs[root];
      g[L].eb(R);
      g[R].eb(L);
    }
  }

  map<int, RootedTree*> rooted_trees;
  each(root, graph, graphs) rooted_trees[root] = new RootedTree(graph);

  V<int> state(N);
  each(a, b, bomb) state[a] = b;

  V<pair<int, int>> is;
  int i = 0;
  while (i < N) {
    while (i < N && state[i] == 0) ++i;
    int j = i;
    while (j < N && state[j] == 1) ++j;
    is.eb(i, j);
    i = j;
  }

  V<int> use(m);
  each(l, r, is) {
    if (!ds.Same(l, r)) {
      wt(-1);
      return;
    }
    int root = ds.Find(l);
    const auto& c = *compressors[root];
    int L = c(l), R = c(r);
    const auto& rt = *rooted_trees[root];
    int lca = rt.LCA(L, R);
    auto f = [&](int node) {
      while (node != lca) {
        int parent = rt.Parent(node);
        use[idx[pack(c.coord[node], c.coord[parent])]] ^= 1;
        node = parent;
      }
    };
    f(L);
    f(R);
  }

  V<int> ans;
  rep(i, m) if (use[i]) ans.eb(i + 1);
  wt(sz(ans));
  wt(ans);
}
