#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(H, W, K);
  vector g(H, vector(W, ' '));
  rep(K) {
    ints(h, w);
    rd(char, c);
    g[h - 1][w - 1] = c;
  }
  vector dp(H, vector(W, mint(0)));
  dp[0][0] = mint(3).Pow(H * W - K);
  mint f = 2;
  f /= 3;
  rep(i, H) rep(j, W) {
    char c = g[i][j];
    if (i + 1 < H) {
      mint cnt = 0;
      if (c == 'X' || c == 'D') {
        cnt = 1;
      } else if (c == ' ') {
        cnt = f;
      }
      dp[i + 1][j] += dp[i][j] * cnt;
    }
    if (j + 1 < W) {
      mint cnt = 0;
      if (c == 'X' || c == 'R') {
        cnt = 1;
      } else if (c == ' ') {
        cnt = f;
      }
      dp[i][j + 1] += dp[i][j] * cnt;
    }
  }
  wt(dp[H - 1][W - 1]);
}
