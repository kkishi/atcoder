#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"

using mint = atcoder::modint;

void Main() {
  ints(n, p);
  mint::set_mod(p);
  vector dp(n + 1, vector(n + 1, mint(0)));
  vector ddp(n + 1, vector(n + 1, mint(0)));
  ddp[0][0] = 1;
  ddp[1][0] = -1;
  rep(y, n + 1) rep(x, n + 1) {
    dp[x][y] += ddp[x][y];
    if (x > 0) dp[x][y] += dp[x - 1][y];
    auto add = [&](int dx, int dy, int sign) {
      int nx = x + dx;
      int ny = y + dy;
      if (nx <= n && ny <= n) ddp[nx][ny] += sign * dp[x][y] * 25;
    };
    add(1, 2, 1);
    add(10, 2, -1);
    add(10, 3, 1);
    add(100, 3, -1);
    add(100, 4, 1);
    add(1000, 4, -1);
    add(1000, 5, 1);
  }
  mint ans = 0;
  rep(i, n) ans += dp[n][i];
  ans = ans / 25 * 26;
  wt(ans.val());
}
