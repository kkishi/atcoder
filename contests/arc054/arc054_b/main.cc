#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, p);
  double lo = 0, hi = p;
  auto f = [&p](double x) { return x + p / pow(2, x / 1.5); };
  rep(200) {
    double x = (hi - lo) / 3;
    double y = f(lo + x);
    double z = f(hi - x);
    if (y < z) {
      hi -= x;
    } else {
      lo += x;
    }
  }
  wt(f(lo));
}
