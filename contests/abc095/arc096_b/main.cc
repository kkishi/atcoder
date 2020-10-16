#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, c);
  V<int> x(n), v(n);
  rep(i, n) cin >> x[i] >> v[i];
  auto f = [&n](const V<int>& x, const V<int>& v) {
    V<int> y(n + 1);
    int p = 0;
    int c = 0;
    rep(i, n) {
      c = c + v[i] - (x[i] - p);
      p = x[i];
      y[i + 1] = max(y[i], c);
    }
    return y;
  };
  V<int> rx = x;
  reverse(all(rx));
  rep(i, n) rx[i] = c - rx[i];
  V<int> rv = v;
  reverse(all(rv));

  V<int> l = f(x, v);
  V<int> r = f(rx, rv);

  int ans = max(l[n], r[n]);
  rep(i, 1, n) {
    chmax(ans, l[i] - x[i - 1] + r[n - i]);
    chmax(ans, r[i] - rx[i - 1] + l[n - i]);
  }
  wt(ans);
}
