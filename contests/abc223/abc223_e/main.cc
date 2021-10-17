#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(x, y, a, b, c);
  wt(([&] {
    V<int> xy = {x, y};
    sort(all(xy));
    do {
      V<int> abc = {a, b, c};
      sort(all(abc));
      do {
        int x = xy[0];
        int y = xy[1];
        int a = abc[0];
        int b = abc[1];
        int c = abc[2];
        {
          int Y = y - div_ceil(c, x);
          if (Y > 0) {
            int X = x - div_ceil(a, Y);
            if (X > 0) {
              if (Y * X >= b) return true;
            }
          }
        }
        {
          int ay = div_ceil(a, x);
          int by = div_ceil(b, x);
          int cy = div_ceil(c, x);
          if (ay + by + cy <= y) return true;
        }
      } while (next_permutation(all(abc)));
    } while (next_permutation(all(xy)));
    return false;
  })());
}
