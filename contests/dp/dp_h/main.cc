#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  vector dp(h, vector(w, mint(0)));
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if (j + 1 < w && a[i][j + 1] == '.') dp[i][j + 1] += dp[i][j];
    if (i + 1 < h && a[i + 1][j] == '.') dp[i + 1][j] += dp[i][j];
  }
  wt(dp[h - 1][w - 1]);
}
