#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int ans = big;
  ints(l, r);
  rep(i, l, r) {
    rep(j, i + 1, r + 1) {
      int k = i * j % 2019;
      if (k == 0) {
        wt(0);
        return;
      }
      chmin(ans, k);
    }
  }
  wt(ans);
}
