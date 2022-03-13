#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  V<int> ans(3);
  rep(n) {
    ints(p);
    if (p <= a) {
      ++ans[0];
    } else if (p <= b) {
      ++ans[1];
    } else {
      ++ans[2];
    }
  }
  wt(min(ans));
}
