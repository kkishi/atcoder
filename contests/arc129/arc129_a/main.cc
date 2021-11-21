#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, r);
  int ans = 0;
  rep(i, 61) {
    if (hasbit(n, i)) {
      int L = 1LL << i;
      int R = 2 * L - 1;
      ans += max(0, min(r, R) - max(l, L) + 1);
    }
  }
  wt(ans);
}
