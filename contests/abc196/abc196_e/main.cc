#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int L = -big, H = big, C = 0;
  rep(n) {
    ints(a, t);
    if (t == 1) {
      C += a;
    } else if (t == 2) {
      chmax(L, a - C);
      chmax(H, L);
    } else {
      chmin(H, a - C);
      chmin(L, H);
    }
  }
  ints(q);
  rep(q) {
    ints(x);
    wt(C + min(H, max(L, x)));
  }
}
