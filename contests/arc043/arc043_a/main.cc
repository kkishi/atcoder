#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  rd(double, a, b);
  V<double> s(n);
  cin >> s;
  auto [lo, hi] = minmax_element(all(s));
  double d = *hi - *lo;
  double p;
  if (d == 0) {
    if (b != 0) {
      wt(-1);
      return;
    } else {
      p = 0;
    }
  } else {
    p = b / d;
  }
  double q = a - (p * accumulate(s)) / n;
  wt(p, q);
}
