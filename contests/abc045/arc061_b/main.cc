#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  set<pair<int, int>> s;
  rep(n) {
    ints(a, b);
    --a, --b;
    s.insert({a, b});
  }
  set<pair<int, int>> check;
  for (auto [a, b] : s) {
    rep(i, 3) rep(j, 3) check.insert({a - i, b - j});
  }
  V<int> ans(10);
  for (auto [a, b] : check) {
    if (!inside(a, b, h - 2, w - 2)) continue;
    int cnt = 0;
    rep(i, 3) rep(j, 3) cnt += s.count({a + i, b + j});
    assert(cnt != 0);
    ++ans[cnt];
  }
  wt((h - 2) * (w - 2) - reduce(all(ans)));
  rep(i, 9) wt(ans[i + 1]);
}
