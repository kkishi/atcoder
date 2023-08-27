#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  g.Read(m);
  V<int> seen(n);
  int ma = -big;
  rep(i, n) Fix([&](auto rec, int node, int sum) -> void {
    if (seen[node]) return;
    chmax(ma, sum);
    seen[node] = true;
    each(child, weight, g[node]) rec(child, sum + weight);
    seen[node] = false;
  })(i, 0);
  wt(ma);
}
