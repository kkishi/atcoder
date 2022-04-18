#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n);
  V<int> a(n), b(n), c(n);
  cin >> a >> b >> c;
  sort(a);
  sort(b);
  sort(c);
  V<int> dp(n + 1);
  rep(i, n) dp[i + 1] = dp[i] + CountLT(a, b[i]);
  int ans = 0;
  rep(i, n) ans += dp[CountLT(b, c[i])];
  wt(ans);
}
