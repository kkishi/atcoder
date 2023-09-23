#include <bits/stdc++.h>

#include "atcoder.h"
#include "i128.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n, x, k);
    if (k == 0) {
      wt(1);
      continue;
    }
    auto f = [&](int x, int k) -> int {
      i128 l = x, r = x;
      rep(k) {
        l = l * 2;
        r = r * 2 + 1;
        if (l > n) return 0;
      }
      return min(r, n) - l + 1;
    };
    int ans = f(x, k);
    rep(i, k) {
      int px = x;
      x /= 2;
      if (x == 0) break;
      int rem = k - (i + 2);
      if (rem < 0) break;
      int nx = x * 2 + x * 2 + 1 - px;
      ans += f(nx, rem);
    }
    if (x) ++ans;
    wt(ans);
  }
}
