#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int x = 0, y = 0;
  rep(3) {
    ints(a, b);
    x ^= a;
    y ^= b;
  }
  wt(x, y);
}
