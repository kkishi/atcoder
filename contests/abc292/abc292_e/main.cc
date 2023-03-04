#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(m) {
    ints(u, v);
    g[u - 1].eb(v - 1);
  }
  int ans = -m;
  rep(i, n) {
    V<bool> seen(n);
    Fix([&](auto rec, int node) -> void {
      if (seen[node]) return;
      seen[node] = true;
      ++ans;
      each(child, g[node]) rec(child);
    })(i);
    --ans;
  }
  wt(ans);
}
