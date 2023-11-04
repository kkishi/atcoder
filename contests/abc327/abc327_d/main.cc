#include <bits/stdc++.h>

#include "atcoder_yn.h"
#include "graph.h"

bool Main() {
  ints(n, m);
  V<int> a(m), b(m);
  cin >> a >> b;
  Graph g(n);
  rep(i, m) {
    g[a[i] - 1].eb(b[i] - 1);
    g[b[i] - 1].eb(a[i] - 1);
  }
  V<int> col(n, int(-1));
  rep(i, n) if (col[i] == -1) Fix([&](auto rec, int node, int c) -> void {
    col[node] = c;
    each(child, g[node]) {
      if (col[child] == -1) {
        rec(child, 1 - c);
      } else {
        if (col[child] != 1 - c) col[child] = 2;
      }
    }
  })(i, 0);
  each(e, col) if (e == 2) return false;
  return true;
}
