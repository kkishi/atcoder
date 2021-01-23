#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  int a = 0;
  rep(i, n) {
    ints(v, p);
    a += v * p;
    if (a > x * 100) {
      wt(i + 1);
      return;
    }
  }
  wt(-1);
}
