#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  vector dp(2, vector(n, vector(n, optional<int>())));
  wt(Fix([&](auto rec, int l, int r, bool taro) -> int {
    auto& d = dp[taro][l][r];
    if (!d) {
      if (l == r) {
        d = taro ? a[l] : -a[l];
      } else {
        int i = rec(l + 1, r, !taro) + (taro ? a[l] : -a[l]);
        int j = rec(l, r - 1, !taro) + (taro ? a[r] : -a[r]);
        if (taro != (i > j)) swap(i, j);
        d = i;
      }
    }
    return *d;
  })(0, n - 1, true));
}
