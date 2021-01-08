#include <bits/stdc++.h>

#include "atcoder.h"
#include "bidirected_graph.h"
#include "modint.h"
#include "rerooting.h"

using mint = ModInt<>;

struct DP {
  int size;
  mint cnt;
  mint fact;
};

DP Combine(DP a, DP b) {
  return {a.size + b.size, a.cnt * b.cnt, a.fact * b.fact};
}

DP Calc(DP x) {
  return {x.size + 1, x.cnt / x.fact * mint::Fact(x.size),
          mint::Fact(x.size + 1)};
}

void Main() {
  ints(N);

  BidirectedGraph<int> graph(N);
  rep(i, N - 1) {
    ints(a, b);
    --a, --b;
    graph.AddEdge(a, b);
  }

  V<DP> res = Rerooting<DP, int>(
      graph, Combine, [](const auto&, DP x) { return Calc(x); }, {0, 1, 1});
  each(r, res) wt(Calc(r).cnt);
}
