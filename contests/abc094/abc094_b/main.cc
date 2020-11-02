#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, m, x);
  int lo = 0, hi = 0;
  rep(i, m) {
    ints(a);
    (a < x ? lo : hi)++;
  }
  wt(min(lo, hi));
}
