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
  V<int> c(n);
  cin >> c;
  sort(all(c));

  int ci = 0;
  V<int> ans(n);
  Fix([&](auto dfs, int n, int p) -> void {
    for (int c : to[n]) {
      if (c == p) continue;
      dfs(c, n);
    }
    ans[n] = c[ci];
    ++ci;
  })(0, -1);

  wt(accumulate(c.begin(), c.end() - 1, 0));
  wt(ans);
}
