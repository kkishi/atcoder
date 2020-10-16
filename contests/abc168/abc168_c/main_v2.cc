#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, A, B, H, M);

  double pi = acos(-1);
  double at = (H + M / 60) / 12 * 2 * pi;
  double ax = cos(at) * A;
  double ay = sin(at) * A;
  double bt = (M / 60) * 2 * pi;
  double bx = cos(bt) * B;
  double by = sin(bt) * B;
  cout << setprecision(20) << hypot(ax - bx, ay - by) << endl;
}
