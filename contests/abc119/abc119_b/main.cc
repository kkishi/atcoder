#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  double ans = 0;
  rep(n) {
    rd(double, x);
    strings(u);
    if (u == "BTC") {
      x *= 380000;
    }
    ans += x;
  }
  wt(ans);
}
