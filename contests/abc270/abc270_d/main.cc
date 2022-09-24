#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(k);
  cin >> a;
  V<int> dp(n + 1);
  rep(i, n + 1) each(e, a) if (e <= i) chmax(dp[i], i - dp[i - e]);
  wt(dp[n]);
}
