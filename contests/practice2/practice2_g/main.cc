#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(m) {
    ints(a, b);
    g[a].eb(b);
  }

  VV<int> scc = StronglyConnectedComponents(g);
  V<int> scc_index(n);
  rep(i, scc.size()) for (int u : scc[i]) scc_index[u] = i;

  wt(scc.size());
  for (const auto& scci : scc) {
    cout << scci.size();
    for (int j : scci) cout << " " << j;
    cout << endl;
  }
}
