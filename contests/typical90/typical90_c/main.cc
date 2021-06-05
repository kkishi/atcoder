#include <bits/stdc++.h>

#include "atcoder.h"
#include "diameter.h"

void Main() {
  ints(n);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  wt(get<0>(Diameter(g)) + 1);
}
