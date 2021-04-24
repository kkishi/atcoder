#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 8;
  int m = 10;
  wt(n, m);
  Rand r;
  rep(m) {
    int x = r.Int(1, n);
    int y = r.Int(1, n);
    int z = r.Int(3, n);
    wt(x, y, z);
  }
}
