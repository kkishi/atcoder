#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, k, d);
  if (x < 0) x = -x;
  if (x / d > k) {
    wt(x - k * d);
    return;
  }
  int y = x % d;
  k -= x / d;
  k %= 2;
  if (k == 1) y = d - y;
  wt(y);
}
