#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

int Combine(int a, int b) { return max(a, b); }

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(a, b, c);
    g.AddEdge(a - 1, b - 1, c);
  }
  V<int> d(n);
  cin >> d;
  V<int> res = Rerooting<int, int>(
      g, Combine,
      [&](const auto& e, int x) { return max(x, d[e.to]) + e.weight; }, 0);
  each(r, res) wt(r);
}
