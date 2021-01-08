#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
  }
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
