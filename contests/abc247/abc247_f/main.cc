#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> p(n), q(n);
  cin >> p >> q;
  DisjointSet ds(n);
  rep(i, n) ds.Union(p[i] - 1, q[i] - 1);
  map<int, int> m;
  rep(i, n) m[ds.Find(i)] = ds.Size(i);

  vector dp(200001, vector(2, vector(2, mint(0))));
  dp[2][0][0] = 1;
  dp[2][1][1] = 1;
  // z: whether the first element is covered
  // p: whether the previous element is covered
  // c: whether to cover the current and the previous element
  rep(i, 3, n + 1) rep(z, 2) rep(p, 2) rep(c, 2) if (p || c) {
    dp[i][z][c] += dp[i - 1][z][p];
  }

  mint ans = 1;
  each(_, x, m) {
    if (x == 1) continue;
    ans *= dp[x][0][0] + dp[x][0][1] + dp[x][1][0] + dp[x][1][1] * 2;
  }
  wt(ans);
}
