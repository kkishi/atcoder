#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector dp(n, vector(n, big));
  dp[0][0] = 0;
  queue<pair<int, int>> que;
  que.push({0, 0});
  V<int> sqrt(n * n + 1, -1);
  rep(i, n + 1) sqrt[i * i] = i;
  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    rep(dr, -n, n + 1) {
      int nr = r + dr;
      if (nr < 0 || n <= nr) continue;
      int dc2 = m - dr * dr;
      if (dc2 < 0 || n * n < dc2) continue;
      if (sqrt[dc2] == -1) continue;
      int dc = sqrt[dc2];
      rep(i, 2) {
        int nc = c + dc * (i == 0 ? 1 : -1);
        if (nc < 0 || n <= nc) continue;
        if (chmin(dp[nr][nc], dp[r][c] + 1)) {
          que.push({nr, nc});
        }
      }
    }
  }
  each(e, dp) {
    each(e, e) if (e == big) e = -1;
    wt(e);
  }
}
