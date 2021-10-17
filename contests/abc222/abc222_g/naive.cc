#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(int k) {
  int r = 2;
  rep(i, 1, 1000000) {
    if (r % k == 0) return i;
    r = (r * 10 + 2) % k;
  }
  return -1;
}

void Main() {
  ints(t);
  rep(t) {
    ints(k);
    wt(Solve(k));
  }
}
