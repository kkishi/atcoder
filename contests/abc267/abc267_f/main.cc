#include <bits/stdc++.h>

#include "atcoder.h"
#include "diameter.h"
#include "graph.h"
#include "lca.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  WeightedGraph<int> wg(n);
  rep(i, n) each(c, g[i]) wg[i].eb(c, 1);
  auto [_, a, b] = Diameter(wg);
  RootedTree at(g, a);
  RootedTree bt(g, b);
  ints(q);
  rep(q) {
    ints(u, k);
    --u;
    if (at.Depth(u) >= k) {
      wt(at.Parent(u, k) + 1);
    } else if (bt.Depth(u) >= k) {
      wt(bt.Parent(u, k) + 1);
    } else {
      wt(-1);
    }
  }
}
