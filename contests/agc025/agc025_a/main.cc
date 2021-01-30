#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = big;
  rep(a, 1, n) {
    int b = n - a;
    auto f = [](int x) {
      int r = 0;
      while (x) {
        r += x % 10;
        x /= 10;
      }
      return r;
    };
    chmin(ans, f(a) + f(b));
  }
  wt(ans);
}
