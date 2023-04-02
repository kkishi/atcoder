#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n);
  Graph g(n);
  rep(i, n) {
    ints(a);
    --a;
    g[i].eb(a);
  }
  int ans = 0;
  each(e, StronglyConnectedComponents(g)) {
    if (sz(e) > 1 || (g[e[0]][0] == e[0])) ans += sz(e);
  }
  wt(ans);
}
