#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int L = -big, R = big;
  rep(n) {
    ints(l, r);
    chmax(L, l);
    chmin(R, r);
    int d = L - R;
    if (d <= 0) {
      wt(0);
    } else {
      wt((d + 1) / 2);
    }
  }
}
