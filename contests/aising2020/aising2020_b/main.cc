#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(i, n) {
    ints(a);
    if (((i + 1) & 1) && (a & 1)) {
      ++ans;
    }
  }
  wt(ans);
}
