#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  int a = 1, b = 1;
  rep(k) {
    int c = a + b;
    a = b;
    b = c;
  }
  wt(b, a);
}
