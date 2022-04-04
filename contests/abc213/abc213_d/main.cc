#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  each(e, g) sort(e);
  V<int> ans;
  Fix([&](auto rec, int node, int parent) -> void {
    ans.pb(node + 1);
    each(c, g[node]) {
      if (c != parent) {
        rec(c, node);
      }
    }
    if (parent != -1) ans.pb(parent + 1);
  })(0, -1);
  wt(ans);
}
