#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, h, a, b, c, d, e);
  int ans = big;
  rep(i, n + 1) {
    int x = h + b * i;
    int y = max(0, (n - i) * e + 1 - x);
    int z = div_ceil(y, d + e);
    chmin(ans, i * a + z * c);
  }
  wt(ans);
}
