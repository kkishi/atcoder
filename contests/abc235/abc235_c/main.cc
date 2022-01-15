#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  V<int> ans(q, -1);
  V<int> x(q), k(q);
  map<pair<int, int>, V<int>> Q;
  rep(i, q) {
    cin >> x[i] >> k[i];
    Q[{x[i], k[i]}].pb(i);
  }
  map<int, int> m;
  rep(i, n) {
    ++m[a[i]];
    each(j, (Q[{a[i], m[a[i]]}])) ans[j] = i + 1;
  }
  each(e, ans) wt(e);
}
