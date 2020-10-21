#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  double x = m / 60.0;
  double y = (n % 12 * 60 + m) / (60.0 * 12);
  double z = abs(x - y) * 360;
  wt(min(z, 360 - z));
}
