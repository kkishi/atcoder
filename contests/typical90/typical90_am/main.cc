#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int ans = 0;
  Fix([&](auto rec, int node, int parent) -> int {
    int cnt = 1;
    each(child, g[node]) if (child != parent) cnt += rec(child, node);
    ans += (n - cnt) * cnt;
    return cnt;
  })(0, -1);
  wt(ans);
}
