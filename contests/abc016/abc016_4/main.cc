#include <bits/stdc++.h>

#include "atcoder.h"
#include "geometry.h"

void Main() {
  rd(Point, a, b);
  ints(n);
  V<Point> p(n);
  cin >> p;
  int cnt = 0;
  rep(i, n) if (Intersect(LineSegment{a, b},
                          LineSegment{p[i], p[(i + 1) % n]}))++ cnt;
  wt(cnt / 2 + 1);
}
