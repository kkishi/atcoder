#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> bit(m), c(m);
  rep(i, m) {
    strings(s);
    rep(j, n) if (s[j] == 'Y') bit[i] |= 1 << j;
    cin >> c[i];
  }
  V<int> dp(1 << n, big);
  dp[0] = 0;
  rep(s, 1 << n) rep(i, m) chmin(dp[s | bit[i]], dp[s] + c[i]);
  int ans = dp[(1 << n) - 1];
  if (ans == big) ans = -1;
  wt(ans);
}
