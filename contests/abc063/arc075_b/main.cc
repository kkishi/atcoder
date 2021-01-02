#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, a, b);
  V<int> h(n);
  cin >> h;
  wt(BinarySearch<int>(10000000000LL, 0, [&](int x) {
    V<int> v = h;
    int y = 0;
    rep(i, n) {
      v[i] -= b * x;
      if (v[i] > 0) y += div_ceil(v[i], a - b);
    }
    return y <= x;
  }));
}
