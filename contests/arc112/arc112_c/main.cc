#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> to(n);
  rep(i, 1, n) {
    ints(p);
    to[p - 1].pb(i);
  }
  V<int> size(n);
  Fix([&](auto rec, int node) -> int {
    int ret = 1;
    each(child, to[node]) ret += rec(child);
    size[node] = ret;
    return ret;
  })(0);
  int res = Fix([&](auto rec, int node) -> int {
    V<int> e, o;
    each(child, to[node]) {
      int opp = rec(child);
      (even(size[child]) ? e : o).pb(-opp);
    }
    sort(all(o), greater());
    int ret = 0;
    each(x, e) ret += (x >= 0 || even(sz(o))) ? x : -x;
    rep(i, sz(o)) ret += even(i) ? o[i] : -o[i];
    return 1 - ret;
  })(0);
  wt((res + n) / 2);
}
