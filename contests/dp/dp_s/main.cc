#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(K);
  ints(d);
  vector dp(sz(K), vector(d, mint(0)));
  for (int i = 1; i < K[0] - '0'; ++i) {
    ++dp[0][i % d];
  }
  int x = (K[0] - '0') % d;
  rep(i, 1, sz(K)) {
    rep(j, 10) rep(k, d) {
      int bonus = (k == 0 && j > 0) + (k == x && j < K[i] - '0');
      dp[i][(k + j) % d] += dp[i - 1][k] + bonus;
    }
    (x += K[i] - '0') %= d;
  }
  wt(dp[sz(K) - 1][0] + (x == 0));
}
