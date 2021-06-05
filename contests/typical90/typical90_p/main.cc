#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, c);
  int ans = big;
  rep(i, 10000) {
    rep(j, 10000) {
      if (int x = n - a * i - b * j; x >= 0 && x % c == 0) {
        chmin(ans, i + j + x / c);
      }
    }
  }
  wt(ans);
}
