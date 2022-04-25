#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int t = 1;
  wt(t);
  Rand r;
  rep(t) {
    int n = r.Int(10, 20);
    int a = r.Int(2, 5);
    int b = r.Int(2, 5);
    int x = r.Int(2, 5);
    int y = r.Int(2, 5);
    int z = r.Int(2, 5);
    wt(n, a, b, x, y, z);
  }
}
