#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(d, 16) {
    int x = 1;
    rep(d) x *= 10;
    int y = x;
    while (y <= n) {
      ans += min(n - y + 1, x);
      y *= 10;
      y += x;
    }
  }
  wt(ans);
}
