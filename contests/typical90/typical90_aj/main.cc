#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> x(n), y(n);
  VV<int> v(2);
  rep(i, n) {
    cin >> x[i] >> y[i];
    v[0].pb(x[i] + y[i]);
    v[1].pb(x[i] - y[i]);
  }
  rep(i, 2) sort(v[i]);
  rep(q) {
    ints(i);
    --i;
    V<int> cand = {x[i] + y[i], x[i] - y[i]};
    int ans = -big;
    rep(i, 2) chmax(ans, max(v[i].back() - cand[i], cand[i] - v[i][0]));
    wt(ans);
  }
}
