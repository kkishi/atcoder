#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), c(n);
  rep(i, n) cin >> x[i] >> c[i];
  map<int, set<int>> m;
  rep(i, n) m[c[i]].insert(x[i]);
  set<int> cs{all(c)};
  V<pair<int, int>> lr{{0, 0}, {0, 0}};
  each(ci, cs) {
    int L = *m[ci].begin();
    int R = *prev(m[ci].end());
    V<pair<int, int>> nlr{{L, big}, {R, big}};
    rep(i, 2) {
      auto [pos, cos] = lr[i];
      chmin(nlr[0].second, cos + abs(R - pos) + R - L);
      chmin(nlr[1].second, cos + abs(L - pos) + R - L);
    }
    swap(lr, nlr);
  }
  int ans = big;
  rep(i, 2) {
    auto [pos, cos] = lr[i];
    chmin(ans, abs(pos) + cos);
  }
  wt(ans);
}
