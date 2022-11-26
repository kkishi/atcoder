#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  int n = 5;
  int q = 20;
  wt(n, q);
  rep(q) {
    int t = r.Int(1, 3);
    int num_balls = n;
    if (t == 1) {
      int x = r.Int(1, n);
      int y = r.Int(1, n);
      while (y == x) y = r.Int(1, n);
      wt(1, x, y);
    } else if (t == 2) {
      wt(2, r.Int(1, n));
      ++num_balls;
    } else {
      wt(3, r.Int(1, num_balls));
    }
  }
}
