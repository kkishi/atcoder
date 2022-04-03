#include <bits/stdc++.h>

#include "atcoder.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n, m);
  Graph g(n);
  rep(m) {
    ints(a, b);
    g[a - 1].eb(b - 1);
  }
  int ans = 0;
  for (auto scc : StronglyConnectedComponents(g)) {
    int x = sz(scc);
    ans += x * (x - 1) / 2;
  }
  wt(ans);
}
