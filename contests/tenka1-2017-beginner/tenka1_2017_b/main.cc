#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = numeric_limits<int>::max();
  rep(n) {
    ints(a, b);
    chmin(ans, a + b);
  }
  wt(ans);
}
