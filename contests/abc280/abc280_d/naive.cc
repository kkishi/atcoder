#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(k);
  int f = 1;
  rep(i, 2, 1000) {
    f *= i;
    if (f % k == 0) {
      wt(i);
      return;
    }
  }
}
