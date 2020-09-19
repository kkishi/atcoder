#include <bits/stdc++.h>

#include "atcoder.h"
#include "fast_io.h"
#include "graph.h"
#include "strongly_connected_component.h"
#include "topological_sort.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(m) {
    ints(a, b);
    g.AddEdge(a, b);
  }

  VV<int> scc = StronglyConnectedComponents(g);
  V<int> scc_index(n);
  rep(i, scc.size()) for (int u : scc[i]) scc_index[u] = i;

  Graph<int> h(scc.size());
  rep(u, n) for (const auto& e : g.Edges(u)) {
    int v = e.to;
    int ui = scc_index[u], vi = scc_index[v];
    if (ui != vi) h.AddEdge(ui, vi);
  }
  V<int> ts = TopologicalSort(h);

  wt(scc.size());
  for (int i : ts) {
    cout << scc[i].size();
    for (int j : scc[i]) cout << " " << j;
    cout << endl;
  }
}
