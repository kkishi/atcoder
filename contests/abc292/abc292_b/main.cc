#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> y(n);
  rep(q) {
    ints(k, x);
    --x;
    if (k == 1) y[x] += 1;
    if (k == 2) y[x] += 2;
    if (k == 3) wt(y[x] >= 2);
  }
}
