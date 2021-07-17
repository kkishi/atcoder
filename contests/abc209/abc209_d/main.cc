#include <bits/stdc++.h>

#include "atcoder.h"
#include "lca.h"

void Main() {
  ints(n, q);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
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
