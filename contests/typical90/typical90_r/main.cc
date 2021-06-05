#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, t, l, x, y);
  ints(q);
  const double pi = acos(-1);
  rep(q) {
    rd(double, e);
    double theta = e / t * 2 * pi;
    double Y = -sin(theta) * l / 2;
    double Z = (1 - cos(theta)) * l / 2;
    double d = hypot(x, y - Y);
    wt(atan2(Z, d) / pi * 180);
  }
}
