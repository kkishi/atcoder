#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"

void Main() {
  rd(double, X, Y, R);
  const int c = 10000;
  int x = round(X * c);
  int y = round(Y * c);
  int r = round(R * c);

  int lx = div_ceil(x - r, c) * c;
  int hx = div_floor(x + r, c) * c;
  int ans = 0;
  for (int xi = lx; xi <= hx; xi += c) {
    int dx = abs(x - xi);
    int dy = IntSqrt(r * r - dx * dx);
    int ly = div_ceil(y - dy, c);
    int hy = div_floor(y + dy, c);
    if (hy >= ly) ans += hy - ly + 1;
  }
  wt(ans);
}
