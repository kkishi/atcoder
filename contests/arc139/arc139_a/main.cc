#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int a = 0;
  rep(n) {
    ints(t);
    a >>= t;
    if (a & 1) {
      ++a;
    }
    a |= 1;
    a <<= t;
  }
  wt(a);
}
