#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, x1, y1, r, x2, y2, x3, y3);
  // The circle contains the square.
  auto d2 = [&](int x, int y) {
    auto sq = [](int x) { return x * x; };
    return sq(x - x1) + sq(y - y1);
  };
  if (max({d2(x2, y2), d2(x2, y3), d2(x3, y2), d2(x3, y3)}) <= r * r) {
    wt("YES");
    wt("NO");
    return;
  }
  // The square contains the circle.
  if (x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3) {
    wt("NO");
    wt("YES");
    return;
  }
  wt("YES");
  wt("YES");
}
