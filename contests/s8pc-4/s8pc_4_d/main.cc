#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "rerooting.h"

struct DP {
  int cnt;
  double exp;
};

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(u, v);
    g.AddEdge(u - 1, v - 1);
  }
  V<DP> res = Rerooting<DP, int>(
      g,
      [](DP a, DP b) -> DP {
        return {a.cnt + b.cnt, a.exp + b.exp};
      },
      [](const auto&, DP x) -> DP {
        return {1, 1 + (x.cnt == 0 ? 0 : x.exp / x.cnt)};
      });
  each(r, res) wt(r.exp / r.cnt);
}
