#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n), c(n);
  cin >> a >> b >> c;
  sort(all(a));
  sort(all(b));
  sort(all(c));
  V<int> dp(n + 1);
  rep(i, n) dp[i + 1] = dp[i] + lower_bound(all(a), b[i]) - a.begin();
  int ans = 0;
  rep(i, n) ans += dp[lower_bound(all(b), c[i]) - b.begin()];
  wt(ans);
}
