#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> b(n + 1), r(n + 1);
  b[1] = 1;
  rep(i, 2, n + 1) {
    b[i] = r[i - 1] + y * b[i - 1];
    r[i] = r[i - 1] + x * b[i];
  }
  wt(r[n]);
}
