#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph to(n);
  to.Read();
  auto rec = Fix([&to](auto rec, int n, int p) -> pair<int, int> {
    int node = n;
    int dist = 0;
    for (int c : to[n]) {
      if (c == p) continue;
      auto [rnode, rdist] = rec(c, n);
      if (chmax(dist, rdist + 1)) node = rnode;
    }
    return pair<int, int>{node, dist};
  });
  auto [a, d1] = rec(0, -1);
  auto [b, d2] = rec(a, -1);
  wt(a + 1, b + 1);
}
