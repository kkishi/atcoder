#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  rep(i, n) {
    ints(c);
    rep(c) {
      ints(p);
      --p;
      g[i].eb(p);
    }
  }
  V<int> visited(n);
  V<int> ans;
  Fix([&](auto rec, int node) {
    if (visited[node]) return;
    visited[node] = true;
    each(child, g[node]) rec(child);
    ans.eb(node + 1);
  })(0);
  ans.pop_back();
  wt(ans);
}
