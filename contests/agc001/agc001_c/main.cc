#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  VV<int> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  auto rec = Fix([&](auto rec, int n, int p, int d, int l) -> int {
    int r = d >= l;
    each(c, to[n]) if (c != p) r += rec(c, n, d + 1, l);
    return r;
  });
  int ans = big;
  rep(i, n) {
    V<int> a, b;
    each(c, to[i]) {
      a.pb(rec(c, i, 0, k / 2));
      b.pb(rec(c, i, 0, (k + 1) / 2));
    }
    int s = accumulate(a);
    rep(i, sz(a)) chmin(ans, s - (a[i] - b[i]));
  }
  wt(ans);
}
