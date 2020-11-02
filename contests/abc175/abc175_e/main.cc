#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  using A = array<int, 4>;

  ints(R, C, K);
  V<int> r(K), c(K), v(K);
  rep(i, K) cin >> r[i] >> c[i] >> v[i];
  VV<int> item(R + 1, V<int>(C + 1));
  rep(i, K) item[r[i]][c[i]] = v[i];
  VV<A> dp(R + 1, V<A>(C + 1));
  rep(i, R) rep(j, C) {
    rep(t, 4) {
      chmax(dp[i + 1][j + 1][0], dp[i][j + 1][t]);
      chmax(dp[i + 1][j + 1][t], dp[i + 1][j][t]);
    }
    rrep(t, 3) {
      chmax(dp[i + 1][j + 1][t + 1], dp[i + 1][j + 1][t] + item[i + 1][j + 1]);
    }
  }
  wt(*max_element(all(dp[R][C])));
}
