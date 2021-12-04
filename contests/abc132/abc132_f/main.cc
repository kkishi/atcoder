#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"
#include "quotients.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  V<pair<int, int>> qs = Quotients(n);
  sort(all(qs), greater{});
  int N = sz(qs);
  vector dp(k + 1, vector(N, mint(0)));
  dp[0][0] = 1;
  rep(i, k) {
    V<mint> d(N + 1);
    rep(j, N) {
      d[0] += dp[i][j];
      d[N - j] -= dp[i][j];
    }
    rep(j, N) {
      dp[i + 1][j] = d[j] * qs[j].second;
      d[j + 1] += d[j];
    }
  }
  wt(accumulate(all(dp[k]), mint(0)));
}
