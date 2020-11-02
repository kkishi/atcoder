#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  for (int x = 1; x <= n; ++x) {
    if (x * 108 / 100 == n) {
      wt(x);
      return;
    }
  }
  wt(":(");
}
