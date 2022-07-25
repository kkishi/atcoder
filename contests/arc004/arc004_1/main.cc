#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<complex<double>> v;
  rep(n) {
    rd(double, x, y);
    v.eb(x, y);
  }
  double ans = 0;
  rep(i, n) rep(j, i) chmax(ans, abs(v[i] - v[j]));
  cout << setprecision(6);
  wt(ans);
}
