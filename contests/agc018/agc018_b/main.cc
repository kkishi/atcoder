#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> a(n, V<int>(m));
  cin >> a;
  for (auto& x : a)
    for (auto& y : x) --y;
  V<bool> use(m, true);
  V<int> pos(n, 0);

  set<pair<int, int>, greater<>> by_cnt;
  map<int, int> by_id;
  rep(i, m) {
    by_cnt.insert({0, i});
    by_id[i] = 0;
  }
  auto change = [&](int id, int v) {
    int cnt = by_id[id];
    by_cnt.erase({cnt, id});
    by_id[id] = cnt + v;
    by_cnt.insert({cnt + v, id});
  };

  rep(i, n) change(a[i][0], 1);

  int ans = by_cnt.begin()->first;
  rep(m - 1) {
    auto [cnt, id] = *by_cnt.begin();
    change(id, -cnt);
    use[id] = false;
    rep(i, n) if (!use[a[i][pos[i]]]) {
      while (!use[a[i][pos[i]]]) {
        ++pos[i];
      }
      change(a[i][pos[i]], 1);
    }
    chmin(ans, by_cnt.begin()->first);
  }
  wt(ans);
}
