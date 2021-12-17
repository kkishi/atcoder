#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> v(n);
  iota(all(v), 0);
  rep(m) {
    ints(x, y);
    v[x - 1] = y - 1;
  }
  each(e, v) wt(e + 1);
}
