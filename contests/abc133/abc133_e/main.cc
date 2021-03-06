#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  VV<int> graph(n + 1);
  rep(i, n - 1) {
    ints(a, b);
    graph[a].pb(b);
    graph[b].pb(a);
  }
  wt(Fix([&](auto dfs, int node, int parent, int d1, int d2) -> mint {
    int remaining = k - (d1 + d2);
    if (remaining <= 0) return 0;
    mint ret = remaining;
    for (int child : graph[node]) {
      if (child == parent) continue;
      ret *= dfs(child, node, 1, d1);
      ++d1;
    }
    return ret;
  })(1, -1, 0, 0));
}
