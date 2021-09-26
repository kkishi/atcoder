#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

struct DP {
  int size;
  int sum;
};

DP Combine(DP a, DP b) { return {a.size + b.size, a.sum + b.sum}; }

DP Calc(DP x) { return {x.size + 1, x.size + x.sum}; }

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(u, v);
    g.AddEdge(u - 1, v - 1);
  }
  V<DP> res = Rerooting<DP, int>(
      g, Combine, [](const auto&, DP x) { return Calc(x); }, {0, 0});
  each(r, res) wt(Calc(r).sum);
}
