#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  for (int l = 1;; ++l) {
    int x = l * (l - 1) / 2;
    if (x > n) break;
    int y = n - x;
    if (y == 0) continue;
    if (y % l == 0) ans += 2;
  }
  wt(ans);
}
