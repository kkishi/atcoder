#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<double> x(n), y(n), c(n);
  rep(i, n) cin >> x[i] >> y[i] >> c[i];
  wt(BinarySearch<double>(big, 0, [&](double t) {
    auto f = [&](const V<double>& v) {
      double lo = v[0] - t / c[0];
      double hi = v[0] + t / c[0];
      rep(i, 1, n) {
        chmax(lo, v[i] - t / c[i]);
        chmin(hi, v[i] + t / c[i]);
      }
      return lo <= hi;
    };
    return f(x) && f(y);
  }));
}
