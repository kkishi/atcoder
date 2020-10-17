#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> cnt(4);
  rep(i, n)++ cnt[a[i]];
  vector dp(n + 1, vector(n + 1, vector(n + 1, optional<double>())));
  wt(Fix([&](auto rec, int i, int j, int k) -> double {
    auto& d = dp[i][j][k];
    if (!d) {
      int tot = i + j + k;
      if (tot == 0) {
        d = 0;
      } else {
        d = 1;
        if (i > 0) *d += rec(i - 1, j + 1, k) * i / n;
        if (j > 0) *d += rec(i, j - 1, k + 1) * j / n;
        if (k > 0) *d += rec(i, j, k - 1) * k / n;
        *d *= n / double(tot);
      }
    }
    return *d;
  })(cnt[3], cnt[2], cnt[1]));
}
