#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<pair<int, int>> x(n), y(n);
  rep(i, n) {
    ints(xi, yi);
    x[i] = {xi, i};
    y[i] = {yi, i};
  }
  sort(all(x));
  sort(all(y));
  V<tuple<int, int, int>> v;
  rep(i, n - 1) {
    v.pb({x[i + 1].first - x[i].first, x[i].second, x[i + 1].second});
    v.pb({y[i + 1].first - y[i].first, y[i].second, y[i + 1].second});
  }
  sort(all(v));
  DisjointSet ds(n);
  int ans = 0;
  for (auto [d, i, j] : v)
    if (!ds.Same(i, j)) {
      ans += d;
      ds.Union(i, j);
    }
  wt(ans);
}
