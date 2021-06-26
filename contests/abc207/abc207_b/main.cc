#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, d);
  c *= d;
  if (b >= c) {
    wt(-1);
    return;
  }
  for (int i = 1;; ++i) {
    int B = a + b * i;
    int R = c * i;
    if (B <= R) {
      wt(i);
      return;
    }
  }
}
