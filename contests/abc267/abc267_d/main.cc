#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  vector dp(n + 1, -big);
  dp[0] = 0;
  each(e, a) rrep(i, n) chmax(dp[i + 1], dp[i] + e * (i + 1));
  wt(dp[m]);
}
