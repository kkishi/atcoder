#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  vector<vector<int>> g(n + 1);
  rep(i, n - 1) {
    ints(a, b);
    g[a].pb(b);
    g[b].pb(a);
  }
  vector<int> xs(n + 1);
  rep(i, q) {
    ints(p, x);
    xs[p] += x;
  }
  vector<int> result(n + 1);
  Fix([&](auto dfs, int x, int node, int parent) -> void {
    x += xs[node];
    result[node] = x;
    for (int child : g[node]) {
      if (child == parent) continue;
      dfs(x, child, node);
    }
  })(0, 1, -1);
  rep(i, n) {
    if (i) cout << " ";
    cout << result[i + 1];
  }
  cout << endl;
}
