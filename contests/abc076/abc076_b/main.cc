#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int x = 1;
  rep(i, n) {
    if (k < x) {
      x += k;
    } else {
      x *= 2;
    }
  }
  wt(x);
}
