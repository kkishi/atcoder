#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> v;
  rep(n) {
    ints(c);
    auto it = lower_bound(all(v), c);
    if (it == v.end()) {
      v.push_back(c);
    } else {
      *it = c;
    }
  }
  wt(n - sz(v));
}
