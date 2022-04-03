#include <bits/stdc++.h>

#include "atcoder.h"
#include "diameter.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }
  wt(get<0>(Diameter(g)) % 3 == 1 ? "Second" : "First");
}
