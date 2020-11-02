#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> a(n, V<int>(n - 1));
  cin >> a;

  set<pair<int, int>> s1;
  set<pair<int, int>> s2;
  V<int> indice(n);
  auto advance = [&](int x) {
    int y = a[x][indice[x]] - 1;
    ++indice[x];
    if (x > y) swap(x, y);
    const auto it = s1.insert({x, y});
    if (!it.second) {
      s2.insert({x, y});
    }
  };
  rep(i, n) advance(i);
  int ans = 0;
  int completed = 0;
  while (true) {
    V<pair<int, int>> v(all(s2));
    if (v.empty()) {
      wt(-1);
      return;
    }
    for (const auto p : v) {
      advance(p.first);
      advance(p.second);
      s2.erase(p);
      ++completed;
    }
    ++ans;
    if (completed == n * (n - 1) / 2) break;
  }
  wt(ans);
}
