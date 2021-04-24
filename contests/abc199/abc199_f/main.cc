#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 18;
  int m = 100;
  Rand r;
  rep(m) {
    int x = r.Int(1, n);
    int y = r.Int(1, n);
    int z = r.Int(1, n);
    wt(x, y, z);
  }
}
