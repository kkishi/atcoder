#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, a, b);
  int e = 0;
  while (x < y - 1) {
    if (__int128_t(x) * (a - 1) < b) {
      x *= a;
      ++e;
      continue;
    }
    int z = (y - x - 1) / b;
    x += z * b;
    e += z;
    break;
  }
  wt(e);
}
