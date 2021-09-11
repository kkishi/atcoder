#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  set<pair<int, int>> s;
  rep(i, n) {
    cin >> x[i] >> y[i];
    s.emplace(x[i], y[i]);
  }
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) {
    if (x[i] == x[j] || y[i] == y[j]) continue;
    if (s.count({x[i], y[j]}) && s.count({x[j], y[i]})) ++ans;
  }
  wt(ans / 2);
}
