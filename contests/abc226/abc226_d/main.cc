#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  bool vertical = false, horizontal = false;
  V<set<pair<int, int>>> st(2);
  rep(i, n) rep(j, i + 1, n) {
    int X = x[j] - x[i];
    int Y = y[j] - y[i];
    if (X == 0) {
      vertical = true;
      continue;
    }
    if (Y == 0) {
      horizontal = true;
      continue;
    }
    if (X < 0) {
      X = -X;
      Y = -Y;
    }
    bool neg = false;
    if (Y < 0) {
      neg = true;
      Y = -Y;
    }
    int g = gcd(X, Y);
    X /= g;
    Y /= g;
    st[neg].emplace(X, Y);
  }
  int ans = 0;
  if (vertical) ++ans;
  if (horizontal) ++ans;
  dbg(ans);
  each(e, st) {
    ans += sz(e);
    dbg(e);
  }
  wt(ans * 2);
}
