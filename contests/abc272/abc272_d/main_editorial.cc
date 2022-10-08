#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<pair<int, int>> d;
  rep(i, -n, n + 1) rep(j, -n, n + 1) {
    if (i * i + j * j == m) d.eb(i, j);
  }
  vector dp(n, vector(n, big));
  dp[0][0] = 0;
  queue<pair<int, int>> que;
  que.push({0, 0});
  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    each(dr, dc, d) {
      int nr = r + dr;
      int nc = c + dc;
      if (inside(nr, nc, n, n) && chmin(dp[nr][nc], dp[r][c] + 1)) {
        que.push({nr, nc});
      }
    }
  }
  each(e, dp) {
    each(e, e) if (e == big) e = -1;
    wt(e);
  }
}
