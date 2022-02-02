#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<complex<double>> c;
  rep(i, n) {
    rd(double, x, y);
    c.eb(x, y);
  }
  double ans = 0;
  rep(i, n) rep(j, i + 1, n) chmax(ans, abs(c[i] - c[j]));
  wt(ans);
}
