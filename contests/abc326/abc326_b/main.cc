#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  for (;; ++n) {
    auto ok = [](int n) -> bool {
      int x = n % 10;
      n /= 10;
      int y = n % 10;
      n /= 10;
      return n * y == x;
    };
    if (ok(n)) {
      wt(n);
      break;
    }
  }
}
