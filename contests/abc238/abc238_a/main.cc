#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n);
    int a = 1;
    rep(n) {
      a *= 2;
      if (a > n * n) return true;
    }
    return false;
  }());
}
