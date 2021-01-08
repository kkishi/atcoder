#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<pair<int, int>> wh(n);
  cin >> wh;
  rep(i, n) wh[i].second *= -1;
  sort(all(wh));
  V<int> v;
  for (auto [_, h] : wh) {
    h *= -1;
    auto it = lower_bound(all(v), h);
    if (it == v.end()) {
      v.pb(h);
    } else {
      *it = h;
    }
  }
  wt(sz(v));
}
