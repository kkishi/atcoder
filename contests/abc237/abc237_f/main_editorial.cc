#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  vector dp(n + 1, vector(m + 1, vector(m + 1, vector(m + 1, mint(0)))));
  dp[0][0][0][0] = 1;
  rep(i, n) rep(a, m + 1) rep(b, m + 1) rep(c, m + 1) rep(j, 1, m + 1) {
    int na = a, nb = b, nc = c;
    if (a == 0 || j <= a) {
      na = j;
    } else if (b == 0 || j <= b) {
      nb = j;
    } else if (c == 0 || j <= c) {
      nc = j;
    } else {
      continue;
    }
    dp[i + 1][na][nb][nc] += dp[i][a][b][c];
  }
  mint ans = 0;
  rep(a, m) rep(b, m) rep(c, m) ans += dp[n][a + 1][b + 1][c + 1];
  wt(ans);
}
