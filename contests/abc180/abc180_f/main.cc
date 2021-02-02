#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m, l);

  // Number of ways to construct a path graph of size n.
  V<mint> path(n + 1);
  path[1] = path[2] = 1;
  rep(i, 3, n + 1) path[i] = path[i - 1] * i;

  auto solve = [&](int l) {
    vector dp(n + 1, vector(m + 1, mint(0)));
    dp[0][0] = 1;
    rep(i, n + 1) rep(j, m + 1) {
      if (dp[i][j] == 0) continue;
      int rn = n - i;  // Remaining nodes.
      int re = m - j;  // Remaining edges.
      // Use one node.
      if (rn >= 1) {
        dp[i + 1][j] += dp[i][j];
      }
      // Use un nodes.
      for (int un = 2; un <= rn && un <= l; ++un) {
        mint c = mint::Comb(rn - 1, un - 1);
        // Path.
        if (int ue = un - 1; ue <= re) {
          dp[i + un][j + ue] += dp[i][j] * c * path[un];
        }
        // Loop.
        if (int ue = un; ue <= re) {
          dp[i + un][j + ue] += dp[i][j] * c * path[un - 1];
        }
      }
    }
    return dp[n][m];
  };
  wt(solve(l) - solve(l - 1));
}
