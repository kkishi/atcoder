#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector<vector<pair<int, int>>> v(n);
  rep(i, m) {
    ints(p, y);
    v[p - 1].pb({y, i});
  }
  for (auto& vi : v) sort(vi);
  vector<pair<int, int>> px(m);
  rep(i, n) rep(x, v[i].size()) px[v[i][x].second] = {i, x};
  for (auto [p, x] : px) printf("%06d%06d\n", p + 1, x + 1);
}
