#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, k);
  vector a(n, vector(n, int(0)));
  cin >> a;
  vector b(n, vector(n, int(0)));
  wt(BinarySearch<int>(big, -1, [&](int x) {
    rep(i, n) rep(j, n) b[i][j] = (a[i][j] <= x);
    CumulativeSum2D sum(b);
    rep(i, k - 1, n) rep(j, k - 1, n) {
      int s = sum.Get(i - k + 1, j - k + 1, i, j);
      int t = (k * k + 1) / 2;
      if (s >= t) return true;
    }
    return false;
  }));
}
