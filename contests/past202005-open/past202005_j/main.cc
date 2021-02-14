#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> lis;
  rep(m) {
    ints(a);
    a = -a;
    auto it = lower_bound(all(lis), a + 1);
    if (it == lis.end()) {
      if (lis.size() == n) {
        wt(-1);
      } else {
        wt(sz(lis) + 1);
        lis.push_back(a);
      }
    } else {
      wt(it - lis.begin() + 1);
      *it = a;
    }
  }
}
