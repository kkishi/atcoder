#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> to(n);
  rep(i, 1, n) {
    ints(p);
    to[p - 1].pb(i);
  }
  auto [res, _] = Fix([&](auto rec, int node) -> pair<int, int> {
    V<int> e, o;
    int size = 1;
    each(child, to[node]) {
      auto [opp, csize] = rec(child);
      (even(csize) ? e : o).pb(-opp);
      size += csize;
    }
    int ret = 0;
    each(x, e) ret += (x >= 0 || even(sz(o))) ? x : -x;
    sort(all(o), greater());
    rep(i, sz(o)) ret += even(i) ? o[i] : -o[i];
    return {1 - ret, size};
  })(0);
  wt((res + n) / 2);
}
