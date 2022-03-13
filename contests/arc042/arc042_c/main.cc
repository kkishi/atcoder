#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  V<pair<int, int>> ab;
  rep(i, n) ab.eb(a[i], b[i]);
  sort(ab, greater{});

  V<int> dp(p + 101);
  int ans = 0;
  for (auto [a, b] : ab) {
    rrep(j, p + 101 - a) {
      chmax(dp[j + a], dp[j] + b);
      if (j <= p) chmax(ans, dp[j + a]);
    }
  }
  wt(ans);
}
