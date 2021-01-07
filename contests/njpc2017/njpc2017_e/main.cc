#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

struct Data {
  bool good;
  int dist;
};

struct DP {
  int depth;
  int change;
};

void Main() {
  ints(n, d);
  BidirectedGraph<Data> g(n);
  rep(n - 1) {
    ints(a, b, c);
    auto [f, r] = g.AddEdge(a - 1, b - 1);
    f.weight = {true, c};
    r.weight = {false, c};
  }
  TreeDP<DP, Data> tdp(
      g,
      [](DP a, DP b) -> DP {
        return {max(a.depth, b.depth), a.change + b.change};
      },
      [](const auto& e, DP x) -> DP {
        return {x.depth + e.weight.dist, x.change + !e.back->weight.good};
      });
  tdp.DFS(0);
  int ans = big;
  each(r, tdp.Rerooting(0)) if (r.depth <= d) chmin(ans, r.change);
  if (ans == big) ans = -1;
  wt(ans);
}
