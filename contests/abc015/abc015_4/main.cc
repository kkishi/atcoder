#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(w, n, k);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  VV<int> dp(k + 1, V<int>(w + 1));
  rep(i, n) {
    VV<int> ndp = dp;
    rep(j, k) rep(l, w - a[i] + 1) chmax(ndp[j + 1][l + a[i]], dp[j][l] + b[i]);
    swap(dp, ndp);
  }
  int ans = 0;
  for (auto& i : dp)
    for (int j : i) chmax(ans, j);
  wt(ans);
}
