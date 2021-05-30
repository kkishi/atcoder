#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  V<pair<int, int>> xs(n), ys(n);
  rep(i, n) {
    xs[i] = {x[i], i};
    ys[i] = {y[i], i};
  }
  sort(all(xs));
  sort(all(ys));
  V<pair<int, pair<int, int>>> v;
  auto push = [&](const auto& a, const auto& b) {
    int d = abs(a.first - b.first);
    pair<int, int> k = {a.second, b.second};
    if (k.first > k.second) swap(k.first, k.second);
    v.eb(d, k);
  };
  rep(i, 2) rep(j, n - 2, n) push(xs[i], xs[j]);
  rep(i, 2) rep(j, n - 2, n) push(ys[i], ys[j]);
  sort(all(v), greater{});
  set<pair<int, int>> st;
  rep(i, sz(v)) {
    auto [I, J] = v[i].second;
    if (I == J) continue;
    dbg(v[i].first, I, J);
    st.insert(v[i].second);
    if (st.size() == 2) {
      wt(v[i].first);
      break;
    }
  }
}
