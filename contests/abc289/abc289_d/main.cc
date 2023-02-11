#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<bool> ng(100001);
  ints(m);
  rep(m) {
    ints(b);
    ng[b] = true;
  }
  ints(x);
  V<bool> dp(200001);
  dp[0] = true;
  rep(i, x) {
    if (ng[i]) continue;
    if (!dp[i]) continue;
    rep(j, n) dp[i + a[j]] = true;
  }
  wt(dp[x] == true);
}
