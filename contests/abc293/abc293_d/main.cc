#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  V<int> degree(n);
  rep(m) {
    ints(a);
    --a;
    rd(char, b);
    ints(c);
    --c;
    rd(char, d);
    g[a].eb(c);
    g[c].eb(a);
    ++degree[a];
    ++degree[c];
  }
  int x = 0, y = 0;
  V<bool> seen(n);
  rep(i, n) if (!seen[i]) {
    bool ok = true;
    Fix([&](auto rec, int node) -> void {
      if (degree[node] != 2) ok = false;
      if (seen[node]) return;
      seen[node] = true;
      each(child, g[node]) rec(child);
    })(i);
    ++(ok ? x : y);
  }
  wt(x, y);
}
