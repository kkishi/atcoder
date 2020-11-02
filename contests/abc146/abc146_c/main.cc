#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, x);
  int ans = 0;
  for (int d = 1; d <= 10; ++d) {
    int tens = 1;
    rep(i, 1, d) tens *= 10;
    int y = x - (tens * a + d * b);
    if (y >= 0) {
      if (d == 10) {
        ans = tens;
      } else {
        chmax(ans, tens + min(tens * 9 - 1, y / a));
      }
    }
  }
  wt(ans);
}
