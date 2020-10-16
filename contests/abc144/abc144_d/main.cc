#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  const double pi = acos(-1);
  rd(double, a, b, x);
  cout << setprecision(20);
  double half = a * a * b / 2;
  if (x < half) {
    double y = x / (a * b / 2);
    wt(90 - atan(y / b) / pi * 180);
  } else {
    double y = (x - half) / (a * a / 2);
    wt(atan((b - y) / a) / pi * 180);
  }
}
