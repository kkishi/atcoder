#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> t(n + 1), x(n + 1), y(n + 1);
  rep(i, 1, n + 1) cin >> t[i] >> x[i] >> y[i];
  bool ok = true;
  rep(i, n) {
    int d = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    int dt = t[i + 1] - t[i];
    if (d <= dt && even(dt - d)) continue;
    ok = false;
  }
  wt(ok);
}
