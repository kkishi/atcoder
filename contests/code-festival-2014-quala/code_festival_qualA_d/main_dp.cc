#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, k);

  V<int> v;
  while (a) {
    v.pb(a % 10);
    a /= 10;
  }
  v.pb(0);
  reverse(all(v));
  const int n = sz(v);

  vector dp(n + 1, vector(3, vector(2, vector(1 << 10, big))));
  dp[0][0][0][0] = 0;
  rep(i, n) rep(cmp, 3) rep(hasnonzero, 2) rep(used, 1 << 10) rep(j, 10) {
    // cmp ... 0:eq, 1:less, 2:greater
    int ncmp = cmp;
    if (cmp == 0) {
      if (j < v[i]) ncmp = 1;
      if (j > v[i]) ncmp = 2;
    }
    int nhasnonzero = hasnonzero | (j > 0);
    int nused = used;
    if (hasnonzero || j > 0) nused |= 1 << j;
    int d = v[i] - j;
    if (ncmp == 2) d = -d;
    chmin(dp[i + 1][ncmp][nhasnonzero][nused],
          dp[i][cmp][hasnonzero][used] * 10 + d);
  }

  int ans = big;
  rep(cmp, 3) rep(hasnonzero, 2) rep(used, 1 << 10) if (popcount(used) <= k) {
    chmin(ans, dp[n][cmp][hasnonzero][used]);
  }
  wt(ans);
}
