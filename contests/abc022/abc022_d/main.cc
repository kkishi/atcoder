#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n);
  V<Point> a(n), b(n);
  cin >> a >> b;
  auto f = [](const V<Point>& v) {
    Point c;
    for (auto& vi : v) c += vi;
    c.x /= sz(v);
    c.y /= sz(v);
    Float ret = 0;
    for (auto& vi : v) ret += (vi - c).Norm();
    return ret;
  };
  wt(f(b) / f(a));
}
