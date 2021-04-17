#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 40, m = 50, q = 1000;
  wt(n, m, q);
  Rand r;
  rep(q) {
    int t = r.Int(1, 2);
    int x;
    if (t == 1) {
      x = r.Int(1, n);
    } else {
      x = r.Int(1, m);
    }
    wt(t, x, r.Int(1, 100000000));
  }
}
