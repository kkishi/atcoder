#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  using P = pair<int, int>;
  WeightedGraph<P> g(n);
  rep(m) {
    ints(a, b, x, y);
    --a, --b;
    g[a].eb(b, P(x, y));
    g[b].eb(a, P(-x, -y));
  }
  V<bool> seen(n);
  V<int> x(n), y(n);
  Fix([&](auto rec, int node, int nx, int ny) {
    if (seen[node]) return;
    seen[node] = true;
    x[node] = nx;
    y[node] = ny;
    each(child, p, g[node]) {
      auto [dx, dy] = p;
      rec(child, nx + dx, ny + dy);
    }
  })(0, 0, 0);
  rep(i, n) {
    if (seen[i]) {
      wt(x[i], y[i]);
    } else {
      wt("undecidable");
    }
  }
}
