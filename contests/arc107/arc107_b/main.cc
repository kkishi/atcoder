#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int ans = 0;
  for (int x = 2; x <= n * 2; ++x) {
    int y = k + x;
    if (2 <= y && y <= n * 2) {
      auto f = [&](int x) {
        int a = max(x - n, 1);
        int b = min(n, x - 1);
        return b - a + 1;
      };
      ans += f(x) * f(y);
    }
  }
  wt(ans);
}
