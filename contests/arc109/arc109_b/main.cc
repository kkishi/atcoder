#include <bits/stdc++.h>

#include "atcoder.h"

using ld = long double;

void Main() {
  ints(n);
  ld x = sqrt(ld(2) * n + ld(17) / 4) - ld(3) / 2;
  int y = ceil(x) - 1;
  wt(n - y);
}
