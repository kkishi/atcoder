#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  sort(all(x));
  sort(all(y));
  int X = x[sz(x) / 2];
  int Y = y[sz(y) / 2];
  int ans = 0;
  rep(i, n) {
    ans += abs(x[i] - X);
    ans += abs(y[i] - Y);
  }
  wt(ans);
}
