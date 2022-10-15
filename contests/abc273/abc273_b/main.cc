#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, k);
  int y = 1;
  rep(k) {
    int z = x % (y * 10);
    if (z / y >= 5) {
      x += y * 10;
    }
    x -= z;
    y *= 10;
  }
  wt(x);
}
