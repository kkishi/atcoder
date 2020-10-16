#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, d, x);
  rep(y, 10) {
    x = x * r - d;
    wt(x);
  }
}
