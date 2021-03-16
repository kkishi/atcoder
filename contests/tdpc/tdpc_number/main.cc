#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(d);
  strings(n);
  each(e, n) e -= '0';
  int N = sz(n);
  vector dp(N + 1, vector(2, vector(d, mint(0))));
  dp[0][0][0] = 1;
  rep(i, N) rep(less, 2) rep(r, d) rep(j, 10) {
    if (!less && j > n[i]) continue;
    int nless = less | (j < n[i]);
    int nr = (r + j) % d;
    dp[i + 1][nless][nr] += dp[i][less][r];
  }
  mint ans = -1;
  rep(i, 2) ans += dp[N][i][0];
  wt(ans);
}
