#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n);
  cin >> a;
  // dp[i+1][state] = the number of intervals ending at i with state.
  vector dp(n + 1, vector(4, int(0)));
  int ans = 0;
  rep(i, n) {
    if (y <= a[i] && a[i] <= x) {
      int s = ((a[i] == x) << 1) | (a[i] == y);
      // Count an interval starting from i.
      dp[i + 1][s] = 1;
      // Extend the intervals ending at i-1.
      rep(ps, 4) dp[i + 1][s | ps] += dp[i][ps];
      // Count all the intervals ending at i and has both x and y.
      ans += dp[i + 1][3];
    }
  }
  wt(ans);
}
