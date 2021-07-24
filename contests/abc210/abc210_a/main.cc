#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, x, y);
  int ans = 0;
  rep(i, n) {
    if (i + 1 >= a + 1) {
      ans += y;
    } else {
      ans += x;
    }
  }
  wt(ans);
}
