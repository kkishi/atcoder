#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  Graph g(n);
  g.Read();
  wt(Fix([&](auto dfs, int node, int parent, int d1, int d2) -> mint {
    int remaining = k - (d1 + d2);
    if (remaining <= 0) return 0;
    mint ret = remaining;
    for (int child : g[node]) {
      if (child == parent) continue;
      ret *= dfs(child, node, 1, d1);
      ++d1;
    }
    return ret;
  })(0, -1, 0, 0));
}
