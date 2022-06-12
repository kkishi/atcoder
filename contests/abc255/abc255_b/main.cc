#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n, k);
  V<int> a(k);
  cin >> a;
  V<Point> p(n);
  cin >> p;
  V<bool> b(n);
  each(e, a) b[e - 1] = true;
  double ans = 0;
  rep(i, n) {
    if (b[i]) continue;
    double d = big;
    rep(j, n) if (b[j]) chmin(d, (p[i] - p[j]).Norm());
    chmax(ans, d);
  }
  wt(ans);
}
