#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t, n);
  int x = div_ceil(100 * n, t);
  int y = (100 + t) * x / 100;
  wt(y - 1);
}
