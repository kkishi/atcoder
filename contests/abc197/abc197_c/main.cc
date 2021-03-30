#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int ans = big;
  Fix([&](auto rec, int depth, int x) {
    if (depth == n) {
      chmin(ans, x);
      return;
    }
    int nx = 0;
    for (int i = depth; i < n; ++i) {
      nx |= a[i];
      rec(i + 1, x ^ nx);
    }
  })(0, 0);
  wt(ans);
}
