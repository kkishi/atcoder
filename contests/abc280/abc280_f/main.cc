#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, q);
  WeightedGraph<int> g(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c);
    g[b].eb(a, -c);
  }
  V<int> root(n, -1);
  V<int> val(n);
  V<bool> has_loop(n);
  rep(i, n) if (root[i] == -1) {
    Fix([&](auto rec, int node, int value) -> void {
      if (root[node] == -1) {
        root[node] = i;
        val[node] = value;
        each(child, weight, g[node]) rec(child, value + weight);
      } else if (val[node] != value) {
        has_loop[i] = true;
      }
    })(i, 0);
  }
  rep(q) {
    ints(x, y);
    --x, --y;
    if (root[x] != root[y]) {
      wt("nan");
    } else if (has_loop[root[x]]) {
      wt("inf");
    } else {
      wt(-val[x] + val[y]);
    }
  }
}
