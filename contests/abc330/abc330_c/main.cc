#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"

void Main() {
  ints(d);
  int ans = big;
  for (int x = 0;; ++x) {
    int b = IntSqrt(abs(x * x - d));
    rep(y, b, b + 2) chmin(ans, abs(x * x + y * y - d));
    if (x * x > d) break;
  }
  wt(ans);
}
