#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  vector dp(n, vector(n, optional<int>()));
  wt(Fix([&](auto rec, int l, int r) -> int {
    auto& d = dp[l][r];
    if (!d) {
      if (l == r) {
        d = a[l];
      } else {
        d = max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));
      }
    }
    return *d;
  })(0, n - 1));
}
