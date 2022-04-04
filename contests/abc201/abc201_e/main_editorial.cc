#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  g.Read();
  V<int> v(n);
  Fix([&](auto rec, int node, int parent, int value) -> void {
    v[node] = value;
    each(child, weight, g[node]) if (child != parent) {
      rec(child, node, value ^ weight);
    }
  })(0, -1, 0);
  mint ans = 0;
  rep(b, 60) {
    mint one = 0, zero = 0;
    rep(i, n)(hasbit(v[i], b) ? one : zero) += 1;
    ans += mint(2).Pow(b) * (one * zero);
  }
  wt(ans);
}
