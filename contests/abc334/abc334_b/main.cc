#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, m, l, r);
  if (a > l) {
    a -= div_ceil(a - l, m) * m;
  }
  auto f = [&](int x) -> int {
    if (x < a) return 0;
    return (x - a) / m + 1;
  };
  wt(f(r) - f(l - 1));
}
