#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<bool> d(10);
  rep(k) {
    ints(di);
    d[di] = true;
  }
  for (int i = n;; ++i) {
    if ([&](int x) {
          while (x) {
            if (d[x % 10]) return false;
            x /= 10;
          }
          return true;
        }(i)) {
      wt(i);
      return;
    }
  }
}
