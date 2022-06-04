#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);

  ints(q);
  rep(q) {
    ints(x, k);
    --x;
    set<int> seen = {x};
    V<int> nodes = {x};
    int ans = x + 1;
    rep(k) {
      V<int> nnodes;
      each(e, nodes) each(c, g[e]) if (seen.insert(c).second) nnodes.pb(c);
      swap(nodes, nnodes);
      each(e, nodes) ans += e + 1;
    }
    wt(ans);
  }
}
