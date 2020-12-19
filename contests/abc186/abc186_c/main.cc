#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int ans = 0;
  auto f = [](int x, int base) {
    while (x) {
      if (x % base == 7) return false;
      x /= base;
    }
    return true;
  };
  ints(n);
  rep(i, 1, n + 1) if (f(i, 8) && f(i, 10))++ ans;
  wt(ans);
}
