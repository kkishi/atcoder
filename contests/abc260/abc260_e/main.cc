#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> v(m);
  rep(i, n) rep(2) {
    ints(x);
    v[x - 1].pb(i);
  }
  map<int, int> mp;
  int r = 0;
  V<int> ans(m);
  rep(l, m) {
    while (r < m && sz(mp) < n) {
      each(e, v[r])++ mp[e];
      ++r;
    }
    if (sz(mp) < n) break;
    ++ans[r - l - 1];
    if (0 < l) --ans[m - l];
    each(i, v[l]) {
      --mp[i];
      if (mp[i] == 0) mp.erase(i);
    }
  }
  rep(i, m - 1) ans[i + 1] += ans[i];
  wt(ans);
}
