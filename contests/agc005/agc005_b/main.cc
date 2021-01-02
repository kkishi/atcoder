#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> v;
  rep(i, n) {
    ints(a);
    v.eb(a, i);
  }
  sort(all(v));
  set<int> s = {-1, n};
  int ans = 0;
  for (auto [ai, i] : v) {
    auto [it, _] = s.insert(i);
    ans += (i - *prev(it)) * (*next(it) - i) * ai;
  }
  wt(ans);
}
