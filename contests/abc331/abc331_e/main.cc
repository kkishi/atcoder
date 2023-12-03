#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, l);
  V<pair<int, int>> a, b;
  rep(i, n) {
    ints(x);
    a.eb(x, i);
  }
  rep(i, m) {
    ints(x);
    b.eb(x, i);
  }
  sort(a);
  sort(b);
  set<pair<int, int>> bad;
  rep(l) {
    ints(c, d);
    --c, --d;
    bad.emplace(c, d);
  }
  priority_queue<tuple<int, int, int>> que;
  set<pair<int, int>> seen;
  auto push = [&](int i, int j) {
    auto [it, ok] = seen.emplace(a[i].second, b[j].second);
    if (!ok) return;
    que.emplace(a[i].first + b[j].first, i, j);
  };
  push(n - 1, m - 1);
  while (!que.empty()) {
    auto [x, i, j] = que.top();
    que.pop();
    if (!bad.count(pair(a[i].second, b[j].second))) {
      wt(x);
      return;
    }
    if (i > 0) push(i - 1, j);
    if (j > 0) push(i, j - 1);
  }
}
