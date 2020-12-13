#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, t);
  V<pair<int, int>> v;
  v.emplace_back(0, 0);
  rep(m) {
    ints(a, b);
    v.emplace_back(a, b);
  }
  v.emplace_back(t, t);
  int x = 0;
  rep(i, sz(v) - 1) {
    x += v[i + 1].first - v[i].second;
    if (x >= n) {
      wt("No");
      return;
    }
    x -= v[i + 1].second - v[i + 1].first;
    x = max(x, 0);
  }
  wt("Yes");
}
