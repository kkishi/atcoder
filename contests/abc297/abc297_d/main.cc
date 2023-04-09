#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int ans = 0;
  while (a != b) {
    if (a > b) {
      swap(a, b);
    } else {
      int d = b - a;
      int x = div_ceil(d, a);
      b -= x * a;
      ans += x;
    }
  }
  wt(ans);
}
