#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> t(n);
  cin >> t;
  int s = accumulate(t);
  V<bool> dp(s + 1);
  dp[0] = true;
  each(e, t) rrep(i, e, s + 1) if (dp[i - e]) dp[i] = true;
  int ans = big;
  rep(i, s + 1) if (dp[i]) chmin(ans, max(i, s - i));
  wt(ans);
}
