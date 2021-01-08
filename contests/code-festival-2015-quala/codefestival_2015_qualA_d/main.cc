#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m);
  V<int> x(m);
  cin >> x;
  wt(BinarySearch<int>(n * 2, -1, [&](int y) {
    int hi = 1;
    rep(i, m) {
      if (hi < x[i]) {
        int l = x[i] - hi;
        if (l > y) return false;
        hi = max({x[i], hi + y - l, (y - l) / 2 + x[i]}) + 1;
      } else {
        hi = x[i] + y + 1;
      }
    }
    return hi > n;
  }));
}
