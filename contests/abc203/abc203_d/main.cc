#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  vector a(n, vector(n, int(0)));
  cin >> a;
  vector b(n, vector(n, int(0)));
  vector dp(n + 1, vector(n + 1, int(0)));
  wt(BinarySearch<int>(big, -1, [&](int x) {
    rep(i, n) rep(j, n) b[i][j] = (a[i][j] <= x);
    rep(i, n + 1) rep(j, n + 1) dp[i][j] = 0;
    rep(i, n) rep(j, n) dp[i + 1][j + 1] =
        dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + b[i][j];
    rep(I, k, n + 1) rep(J, k, n + 1) {
      int s = dp[I][J] - dp[I - k][J] - dp[I][J - k] + dp[I - k][J - k];
      int t = k * k / 2;
      if (!even(k)) ++t;
      if (s >= t) return true;
    }
    return false;
  }));
}
