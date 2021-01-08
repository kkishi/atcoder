#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> g(n);
  rep(i, n - 1) {
    ints(a);
    g[a - 1].pb(i + 1);
  }
  wt(Fix([&](auto rec, int n) -> int {
    int ret = 0;
    V<int> res;
    for (int c : g[n]) {
      res.pb(rec(c));
    }
    sort(all(res));
    rep(i, sz(res)) chmax(ret, sz(res) - i + res[i]);
    return ret;
  })(0));
}
