#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(y, m, d);
  if (m == 1 || m == 2) {
    --y;
    m += 12;
  }
  int x = 365 * y + (y / 4) - (y / 100) + (y / 400) + (306 * (m + 1) / 10) + d -
          429;
  wt(735369 - x);
}
