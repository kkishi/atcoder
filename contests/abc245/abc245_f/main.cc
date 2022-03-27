#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(m) {
    ints(u, v);
    g.AddEdge(u - 1, v - 1);
  }
  V<bool> ok(n);
  auto scc = StronglyConnectedComponents(g);
  reverse(scc);
  each(e, scc) {
    if (sz(e) > 1) each(f, e) ok[f] = true;
    each(f, e) each(edge, g.Edges(f)) if (ok[edge.to]) ok[f] = true;
  }
  wt(count(all(ok), true));
}
