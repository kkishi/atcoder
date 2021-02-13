#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(l, r);
    int x = r - l - l;
    if (x >= 0) {
      wt((x + 1) * (x + 2) / 2);
    } else {
      wt(0);
    }
  }
}
