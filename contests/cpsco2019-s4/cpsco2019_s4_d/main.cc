#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  wt(BinarySearch<int>(n, 0, [&](int x) {
    int y = 1;
    int z = 0;
    rep(i, n - 1) {
      if (a[i + 1] == a[i]) {
        ++y;
        if (y > x) {
          ++z;
          y = 0;
        }
      } else {
        y = 1;
      }
    }
    return z <= k;
  }));
}
