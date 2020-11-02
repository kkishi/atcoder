#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  int ans = 0;
  rep(i, n) {
    ints(x, y);
    if (x * x + y * y <= d * d) {
      ++ans;
    }
  }
  wt(ans);
}
