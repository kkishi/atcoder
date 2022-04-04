#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  V<int> c(n);
  cin >> c;
  Graph g(n);
  g.Read();
  map<int, int> seen;
  V<bool> ans(n);
  Fix([&](auto rec, int node, int parent) -> void {
    if (seen[c[node]] == 0) {
      ans[node] = true;
    }
    ++seen[c[node]];
    each(child, g[node]) {
      if (child == parent) continue;
      rec(child, node);
    }
    --seen[c[node]];
  })(0, -1);
  rep(i, n) if (ans[i]) wt(i + 1);
}
