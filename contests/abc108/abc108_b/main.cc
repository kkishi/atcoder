#include <bits/stdc++.h>

#include "atcoder.h"

using Point = complex<int>;
Point Rot90(Point p) { return p * Point{0, 1}; }

void Main() {
  ints(x1, y1, x2, y2);
  Point v1 = {x1, y1}, v2 = {x2, y2};
  Point v = v2 - v1;
  Point v3 = v2 + Rot90(v);
  Point v4 = v3 + Rot90(Rot90(v));
  wt(v3.real(), v3.imag(), v4.real(), v4.imag());
}
