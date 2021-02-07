#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"

void Main() {
  rd(double, X, Y, R);
  const int c = 10000;
  int x = round(X * c);
  int y = round(Y * c);
  int r = round(R * c);

  int lx = x - r;
  while (lx % c) ++lx;
  int hx = x + r;
  while (hx % c) --hx;
  int ans = 0;
  for (int xi = lx; xi <= hx; xi += c) {
    int dx = abs(x - xi);
    int dy = IntSqrt(r * r - dx * dx);
    int ly = y - dy;
    while (ly % c) ++ly;
    int hy = y + dy;
    while (hy % c) --hy;
    if (hy >= ly) ans += (hy - ly) / c + 1;
  }
  wt(ans);
}
