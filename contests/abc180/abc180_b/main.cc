#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n);
  cin >> x;
  int m = 0;
  double u = 0;
  int c = -big;
  for (int xi : x) {
    int ax = abs(xi);
    m += ax;
    u += ax * ax;
    chmax(c, ax);
  }
  wt(m);
  wt(sqrt(u));
  wt(c);
}
