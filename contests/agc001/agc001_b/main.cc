#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  int ans = n;
  int y = n - x;
  while (true) {
    int z = y / x;
    int r = y % x;
    if (r == 0) {
      ans += (2 * z - 1) * x;
      break;
    }
    ans += 2 * z * x;
    y = x;
    x = r;
  }
  wt(ans);
}
