#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  ints(n);
  Point a, b;
  cin >> a >> b;
  Point ab = b - a;
  Point c = a + ab / 2.0;
  Point d = c + (-(ab / 2.0) * Point::Polar(1.0, 2 * pi / n));
  wt(d.x, d.y);
}
