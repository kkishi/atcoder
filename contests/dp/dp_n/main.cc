#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> cum(n + 1);
  rep(i, n) cum[i + 1] = cum[i] + a[i];
  vector dp(n + 1, vector(n + 1, optional<int>()));
  wt(Fix([&](auto rec, int begin, int end) -> int {
    if (end - begin == 1) return 0;
    auto& d = dp[begin][end];
    if (!d) {
      d = big;
      for (int mid = begin + 1; mid < end; ++mid) {
        chmin(d, rec(begin, mid) + rec(mid, end) + cum[end] - cum[begin]);
      }
    }
    return *d;
  })(0, n));
}
