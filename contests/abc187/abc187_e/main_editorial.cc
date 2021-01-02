#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> to(n);
  V<pair<int, int>> es;
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
    es.eb(a, b);
  }
  map<pair<int, int>, int> qs;
  ints(q);
  rep(q) {
    ints(t, e, x);
    auto [a, b] = es[e - 1];
    if (t == 2) swap(a, b);
    qs[{a, b}] += x;
  }

  int tot = 0;
  V<int> ans(n);
  Fix([&](auto rec, int n, int p, int x) -> void {
    ans[n] = x;
    for (int c : to[n]) {
      if (c == p) continue;
      tot += qs[{n, c}];
      rec(c, n, x + qs[{c, n}] - qs[{n, c}]);
    }
  })(0, -1, 0);

  rep(i, n) wt(tot + ans[i]);
}
