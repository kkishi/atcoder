#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n);
    V<int> s;
    while (n) {
      s.eb(n % 2);
      n /= 2;
    }
    reverse(s);
    int N = sz(s);
    vector dp(N + 1, vector(2, vector(4, -big)));
    dp[0][0][0] = 0;
    rep(i, N) rep(less, 2) rep(one, 4) rep(j, 2) {
      if (!less && s[i] < j) continue;
      int nd = dp[i][less][one] * 2 + j;
      int nless = less | (s[i] > j);
      int none = one + j;
      if (none == 4) continue;
      chmax(dp[i + 1][nless][none], nd);
    }
    int ans = -1;
    rep(i, 2) chmax(ans, dp[N][i][3]);
    wt(ans);
  }
}
