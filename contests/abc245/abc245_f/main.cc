#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(m) {
    ints(u, v);
    g[u - 1].eb(v - 1);
  }
  V<bool> ok(n);
  auto scc = StronglyConnectedComponents(g);
  reverse(scc);
  each(e, scc) {
    if (sz(e) > 1) each(f, e) ok[f] = true;
    each(f, e) each(to, g[f]) if (ok[to]) ok[f] = true;
  }
  wt(count(all(ok), true));
}
