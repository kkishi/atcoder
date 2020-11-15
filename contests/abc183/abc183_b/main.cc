#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, sx, sy, gx, gy);
  double r = sy / (sy + gy);
  wt(sx + r * (gx - sx));
}
