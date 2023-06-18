#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 500000;
  int k = r.Int(1, n);
  int q = 500000;
  wt(n, k, q);
  rep(q) {
    int x = r.Int(1, n);
    int y = r.Int(1, 1000000000);
    wt(x, y);
  }
}
