#include <bits/stdc++.h>

#include "atcoder.h"

using P = complex<double>;

void Main() {
  ints(n);
  V<P> p;
  rep(i, n) {
    ints(x, y);
    p.eb(x, y);
  }
  double ans = 10;
  const double pi = acos(-1);
  rep(i, n) {
    V<double> v;
    rep(j, n) if (j != i) {
      double a = arg(p[j] - p[i]);
      if (a < 0) a += 2 * pi;
      v.eb(a);
      v.eb(a + 2 * pi);
    }
    sort(v);
    rep(j, sz(v)) {
      double x = v[j] + pi;
      auto it = lower_bound(all(v), x);
      if (it != v.end()) chmin(ans, *it - x);
      if (it != v.begin()) chmin(ans, x - *prev(it));
    }
  }
  wt(180 * (pi - ans) / pi);
}
