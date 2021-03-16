#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  auto f = [](int x) {
    V<int> v;
    while (x) {
      v.pb(x % 10);
      x /= 10;
    }
    reverse(all(v));
    return v;
  };
  auto g = [](const V<int>& v) {
    int n = sz(v);
    vector dp(n + 1, vector(2, vector(2, int(0))));
    dp[0][0][0] = 1;
    rep(i, n) rep(less, 2) rep(ban, 2) rep(j, 10) {
      if (!less && j > v[i]) continue;
      int nless = less | (j < v[i]);
      int nban = ban | (j == 4 || j == 9);
      dp[i + 1][nless][nban] += dp[i][less][ban];
    }
    int ret = 0;
    rep(i, 2) ret += dp[n][i][1];
    return ret;
  };
  wt(g(f(b)) - g(f(a - 1)));
}
