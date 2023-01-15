#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);
  V<bool> seen(n);
  int ans = 0;
  Fix([&](auto rec, int node) {
    seen[node] = true;
    ++ans;
    if (ans == 1000000) {
      return false;
    }
    each(child, g[node]) {
      if (!seen[child]) {
        if (!rec(child)) {
          return false;
        }
      }
    }
    seen[node] = false;
    return true;
  })(0);
  wt(ans);
}
