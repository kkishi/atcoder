#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int x = 1;
  int t = 0;
  for (; x < n; x *= 3, t++) {
    int y = n - x;
    int f = 0;
    while (y % 5 == 0) y /= 5, ++f;
    if (y == 1) {
      if (t > 0 && f > 0) {
        wt(t, f);
        return;
      }
    }
  }
  wt(-1);
}
