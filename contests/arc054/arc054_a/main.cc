#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, x, y, s, d);
  double dist = (d - s + l) % l;
  double ans = dist / (x + y);
  if (y > x) {
    double dist = (s - d + l) % l;
    chmin(ans, dist / (y - x));
  }
  wt(ans);
}
