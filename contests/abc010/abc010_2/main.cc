#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(n) {
    ints(a);
    while (a) {
      if (a % 2 == 0 || a % 3 == 2) {
        --a;
        ++ans;
        continue;
      }
      break;
    }
  }
  wt(ans);
}
