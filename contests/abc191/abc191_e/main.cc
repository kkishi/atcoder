#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n * 2);
  auto in = [](int i) { return i; };
  auto out = [&n](int i) { return i + n; };
  rep(i, n) g[in(i)].eb(out(i), 0);
  rep(m) {
    ints(a, b, c);
    g[out(a - 1)].eb(in(b - 1), c);
  }

  rep(i, n) {
    optional<int> d = Dijkstra(g, out(i)).dist[in(i)];
    if (d) {
      wt(*d);
    } else {
      wt(-1);
    }
  }
}
