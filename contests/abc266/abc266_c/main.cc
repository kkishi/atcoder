#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_geometry.h"

void Main() {
  wt([] {
    V<Point> p(4);
    cin >> p;
    rep(i, 4) {
      if (CCW(p[i], p[(i + 1) % 4], p[(i + 2) % 4]) <= 0) return false;
    }
    return true;
  }());
}
