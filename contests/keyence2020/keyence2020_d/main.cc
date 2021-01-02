#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  vector cost(1 << n, vector<int>(n));
  rep(s, 1 << n) rep(i, n) if (hasbit(s, i)) {
    rep(j, n) if (!hasbit(s, j)) {
      if (j < i) ++cost[s][i];
    }
  }

  vector dp(1 << n, vector<int>(n, big));
  rep(i, n) dp[1 << i][i] = i;
  rep(s, 1 << n) rep(i, n) if (hasbit(s, i)) {
    int p = popcount(s);
    rep(j, n) if (!hasbit(s, j)) {
      int x = (((p - 1) % 2 == i % 2) ? a : b)[i];
      int y = ((p % 2 == j % 2) ? a : b)[j];
      if (x <= y) {
        int ns = s | (1 << j);
        chmin(dp[ns][j], dp[s][i] + cost[ns][j]);
      }
    }
  }

  int ans = big;
  rep(i, n) chmin(ans, dp[(1 << n) - 1][i]);
  wt(ans == big ? -1 : ans);
}
