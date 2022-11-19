#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, m);
  while (true) {
    int b = h % 10;
    int c = m / 10;
    int d = m % 10;
    int H = h - b + c;
    int M = b * 10 + d;
    if (H < 24 && M < 60) {
      wt(h, m);
      return;
    }
    ++m;
    if (m == 60) {
      m = 0;
      ++h;
      if (h == 24) {
        h = 0;
      }
    }
  }
}
