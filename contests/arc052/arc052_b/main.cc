#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> x(n), r(n), h(n);
  rep(i, n) cin >> x[i] >> r[i] >> h[i];
  const double pi = acos(-1);
  cout << setprecision(6);
  rep(q) {
    ints(a, b);
    // Returns the total volume of the objects exist in x >= X.
    auto f = [&](int X) {
      double sum = 0;
      rep(i, n) if (X <= x[i] + h[i]) {
        double minx = max(X, x[i]);
        double ratio = (double)(x[i] + h[i] - minx) / h[i];
        sum += pi * r[i] * r[i] * h[i] / 3 * (ratio * ratio * ratio);
      }
      return sum;
    };
    wt(f(a) - f(b));
  }
}
