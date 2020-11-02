#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, d, e, f);
  // (ai + bj) * e >= (ck + dl)
  int mw = -1, ms = -1;
  for (int i = 0; i * a * 100 <= f; ++i) {
    for (int j = 0; j * b * 100 <= f; ++j) {
      int w = (i * a + j * b) * 100;
      for (int k = 0; k * c <= f; ++k) {
        for (int l = 0; l * d <= f; ++l) {
          int s = k * c + l * d;
          if (0 < w + s && w + s <= f && w / 100 * e >= s) {
            if (mw == -1 || ms * (w + s) < s * (mw + ms)) {
              mw = w;
              ms = s;
            }
          }
        }
      }
    }
  }
  wt(mw + ms, ms);
}
