#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  auto f = [&]() {
    vector dp(n, vector(n, map<int, int>()));
    dp[0][0][a[0][0]] = 1;
    rep(i, n) rep(j, n) {
      if (i + j >= n - 1) break;
      each(e, x, dp[i][j]) {
        if (i + 1 < n) dp[i + 1][j][e ^ a[i + 1][j]] += x;
        if (j + 1 < n) dp[i][j + 1][e ^ a[i][j + 1]] += x;
      }
    }
    return dp;
  };
  auto transpose = [&](auto& v) {
    each(e, v) reverse(e);
    reverse(v);
  };
  vector dpa = f();
  transpose(a);
  vector dpb = f();
  transpose(dpb);
  transpose(a);
  int ans = 0;
  rep(i, n) {
    int j = n - 1 - i;
    each(k, v, dpa[i][j]) ans += v * dpb[i][j][k ^ a[i][j]];
  }
  wt(ans);
}
