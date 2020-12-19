#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

using Vec = Vector<double>;

void Main() {
  ints(n);
  V<Vec> a(n), b(n);
  cin >> a >> b;
  auto f = [](const V<Vec>& v) {
    Vec c;
    for (auto& vi : v) c += vi;
    c.x /= sz(v);
    c.y /= sz(v);
    double ret = 0;
    for (auto& vi : v) ret += (vi - c).Norm();
    return ret;
  };
  wt(f(b) / f(a));
}
