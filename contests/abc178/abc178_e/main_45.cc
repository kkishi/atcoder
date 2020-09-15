#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a, b;
  rep(n) {
    ints(x, y);
    a.push_back(x + y);
    b.push_back(x - y);
  }
  auto [c, d] = minmax_element(all(a));
  auto [e, f] = minmax_element(all(b));
  wt(max(*d - *c, *f - *e));
}
