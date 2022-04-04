#include <bits/stdc++.h>

#include "atcoder.h"
#include "lca.h"

void Main() {
  ints(n, q);
  Graph g(n);
  g.Read();

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
