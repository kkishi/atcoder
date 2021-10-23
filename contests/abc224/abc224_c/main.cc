#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  int ans = 0;
  rep(i, n) rep(j, i + 1, n) rep(k, j + 1, n) {
    int x1 = x[j] - x[i];
    int y1 = y[j] - y[i];
    int x2 = x[k] - x[i];
    int y2 = y[k] - y[i];
    if (x1 * y2 - x2 * y1 != 0) {
      ++ans;
    }
  }
  wt(ans);
}
