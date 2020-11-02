#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, d);
  int n = h * w;
  V<int> R(n), C(n);
  rep(i, h) rep(j, w) {
    ints(a);
    R[a - 1] = i;
    C[a - 1] = j;
  }
  V<int> cum(n);
  rep(i, n - d) cum[i + d] =
      cum[i] + abs(R[i + d] - R[i]) + abs(C[i + d] - C[i]);
  ints(q);
  rep(q) {
    ints(l, r);
    wt(cum[r - 1] - cum[l - 1]);
  }
}
