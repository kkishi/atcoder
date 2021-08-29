#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(a, b, x);
  int ans = 0;
  for (int d = 1; d <= 10; ++d) {
    int tens = Pow(10, d - 1);
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
