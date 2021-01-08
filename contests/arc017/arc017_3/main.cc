#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> wa(n / 2), wb(n - n / 2);
  cin >> wa >> wb;
  auto f = [](const V<int>& w) {
    map<int, int> m;
    rep(s, 1 << sz(w)) {
      int v = 0;
      rep(i, sz(w)) if (hasbit(s, i)) v += w[i];
      ++m[v];
    }
    return m;
  };
  map<int, int> ma = f(wa), mb = f(wb);
  int ans = 0;
  for (auto [k, v] : ma) ans += mb[x - k] * v;
  wt(ans);
}
