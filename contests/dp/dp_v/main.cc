#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

void Main() {
  ints(n, m);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    g.AddEdge(a - 1, b - 1);
  }

  V<int> res = Rerooting<int, int>(
      g, [&](int a, int b) { return a * b % m; },
      [&](const auto&, int x) { return (x + 1) % m; }, 1);
  each(r, res) wt(r);
}
