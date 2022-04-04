#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k, s, t, x);
  --s, --t, --x;
  Graph g(n);
  g.Read(m);
  vector dp(n, vector(2, mint(0)));
  dp[s][0] = 1;
  rep(k) {
    vector ndp(n, vector(2, mint(0)));
    rep(i, n) rep(j, 2) {
      each(ni, g[i]) {
        int nj = (j + (ni == x)) % 2;
        ndp[ni][nj] += dp[i][j];
      }
    }
    swap(dp, ndp);
  }
  wt(dp[t][0]);
}
