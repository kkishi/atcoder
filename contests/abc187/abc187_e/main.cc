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

  V<int> sub(n);
  Fix([&](auto rec, int n, int p) -> int {
    for (int c : to[n]) {
      if (c == p) continue;
      sub[n] += rec(c, n);
    }
    return sub[n] + qs[{p, n}];
  })(0, -1);

  V<int> ans(n);
  Fix([&](auto rec, int n, int p, int x) -> void {
    ans[n] = x + sub[n];
    for (int c : to[n]) {
      if (c == p) continue;
      rec(c, n, ans[n] - sub[c] - qs[{n, c}] + qs[{c, n}]);
    }
  })(0, -1, 0);

  rep(i, n) wt(ans[i]);
}
