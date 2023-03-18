#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "cumulative_sum.h"

void Main() {
  wt([] {
    ints(n, P, Q, R);
    V<int> a(n);
    cin >> a;
    CumulativeSum1D c(a);
    // [l, r)
    auto get = [&](int l, int r) {
      if (r - 1 < l) return int(0);
      return c.Get(l, r - 1);
    };
    rep(l, n) {
      int r = BinarySearch<int>(l, n, [&](int r) { return get(l, r) <= Q; });
      int x = BinarySearch<int>(0, l, [&](int x) { return get(x, l) >= P; });
      int y = BinarySearch<int>(n, r, [&](int y) { return get(r, y) >= R; });
      if (get(l, r) == Q && get(x, l) == P && get(r, y) == R) return true;
    }
    return false;
  }());
}
