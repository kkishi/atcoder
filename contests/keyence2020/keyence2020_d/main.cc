#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  auto bit = [](int s, int i) { return (s >> i) & 1; };

  vector cost(1 << n, vector<int>(n));
  rep(s, 1 << n) rep(i, n) if (bit(s, i)) {
    rep(j, n) if (!bit(s, j)) {
      if (j < i) ++cost[s][i];
    }
  }

  const int inf = numeric_limits<int>::max() / 10;
  vector dp(1 << n, vector<int>(n, inf));
  rep(i, n) dp[1 << i][i] = i;
  rep(s, 1 << n) rep(i, n) if (bit(s, i)) {
    int p = popcount(s);
    rep(j, n) if (!bit(s, j)) {
      int x = (((p - 1) % 2 == i % 2) ? a : b)[i];
      int y = ((p % 2 == j % 2) ? a : b)[j];
      if (x <= y) {
        int ns = s | (1 << j);
        chmin(dp[ns][j], dp[s][i] + cost[ns][j]);
      }
    }
  }

  int ans = inf;
  rep(i, n) chmin(ans, dp[(1 << n) - 1][i]);
  wt(ans == inf ? -1 : ans);
}
