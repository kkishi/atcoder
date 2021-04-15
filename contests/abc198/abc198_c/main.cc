#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, x, y);
  int d2 = x * x + y * y;
  int r2 = r * r;
  if (d2 >= r2) {
    rep(i, 1, 1000000) {
      if (r2 * i * i >= d2) {
        wt(i);
        return;
      }
    }
  } else {
    wt(2);
  }
}
