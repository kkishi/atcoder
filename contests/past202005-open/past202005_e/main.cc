#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, q);
  Graph g(n);
  g.Read(m);
  V<int> c(n);
  cin >> c;
  rep(q) {
    ints(k, x);
    --x;
    wt(c[x]);
    if (k == 1) {
      each(y, g[x]) c[y] = c[x];
    } else {
      ints(y);
      c[x] = y;
    }
  }
}
