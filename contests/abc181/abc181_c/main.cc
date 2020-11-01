#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  bool ok = false;
  rep(i, n) rep(j, i + 1, n) rep(k, j + 1, n) {
    int a = x[j] - x[i];
    int b = x[k] - x[i];
    int c = y[j] - y[i];
    int d = y[k] - y[i];
    if (a * d == c * b) ok = true;
  }
  wt(ok);
}
