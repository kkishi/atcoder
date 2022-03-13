#include <bits/stdc++.h>

#include "atcoder.h"

#define sq(x) (x) * (x)

void Main() {
  ints(n, c);
  V<pair<int, int>> v(n);
  cin >> v;
  sort(v);
  double lo = v[0].first, hi = v[n - 1].first;
  rep(200) {
    double x = (hi - lo) / 3;
    auto f = [&](double x) {
      double ret = 0;
      rep(i, n) ret += sq(x - v[i].first);
      return ret;
    };
    if (f(lo + x) > f(hi - x)) {
      lo += x;
    } else {
      hi -= x;
    }
  }
  double ans = 0;
  each(x, y, v) ans += sq(lo - x) + sq(c - y);
  wt(ans);
}
