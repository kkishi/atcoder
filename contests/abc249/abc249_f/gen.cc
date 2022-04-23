#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 5, k = 2;
  wt(n, k);
  Rand r;
  rep(i, n) {
    int t = r.Int(1, 2);
    int y = r.Int(0, 10) - 5;
    wt(t, y);
  }
}
