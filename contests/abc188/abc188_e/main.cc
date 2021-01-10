#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  VV<int> to(n);
  rep(m) {
    ints(x, y);
    to[x - 1].pb(y - 1);
  }
  V<int> dp(n, big);
  int ans = -big;
  rep(i, n) {
    chmax(ans, a[i] - dp[i]);
    each(c, to[i]) chmin(dp[c], min(dp[i], a[i]));
  }
  wt(ans);
}
