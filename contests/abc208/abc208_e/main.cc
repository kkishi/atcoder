#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> v;
  while (n) {
    v.pb(n % 10);
    n /= 10;
  }
  reverse(v);
  int N = sz(v);
  vector dp(N + 1, vector(2, vector(2, map<int, int>{})));
  dp[0][0][0][0] = 1;
  rep(i, N) rep(less, 2) rep(nonzero, 2) rep(d, 10) {
    if (less == 0 && d > v[i]) continue;
    int nless = less | (d < v[i]);
    int nnonzero = nonzero | (d > 0);
    each(x, y, dp[i][less][nonzero]) {
      int nx = min(big, nonzero ? x * d : d);
      dp[i + 1][nless][nnonzero][nx] += y;
    }
  }
  int ans = 0;
  rep(i, 2) each(x, e, dp[N][i][1]) if (x <= k) ans += e;
  wt(ans);
}
