#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n, a, b, x, y, z);
    int ans = big;
    for (int i = 0; i * a <= n; ++i) {
      for (int j = 0; i * a + j * b <= n; ++j) {
        chmin(ans, i * y + j * z + (n - i * a - j * b) * x);
      }
    }
    wt(ans);
  }
}
