#include <bits/stdc++.h>

#include "atcoder.h"
#include "lca.h"

void Main() {
  ints(n, q);
  Graph g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b);
    g[b].eb(a);
  }
  RootedTree rt(g);
  rep(q) {
    ints(c, d);
    --c, --d;
    int dis = rt.Distance(c, d);
    if (even(dis)) {
      wt("Town");
    } else {
      wt("Road");
    }
  }
}
