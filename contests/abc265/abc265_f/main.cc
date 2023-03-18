// This fails with after_contest cases.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, d);
  V<int> p(n), q(n);
  cin >> p >> q;
  vector dp(d + 1, vector(d + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    vector ndp(d + 1, vector(d + 1, mint(0)));
    rep(j, d + 1) rep(k, d + 1) if (dp[j][k] != 0) {
      int L = max(p[i] - (d - j), q[i] - (d - k));
      int R = min(p[i] + (d - j), q[i] + (d - k));
      rep(r, L, R + 1) {
        int nj = j + abs(p[i] - r);
        int nk = k + abs(q[i] - r);
        ndp[nj][nk] += dp[j][k];
      }
    }
    swap(dp, ndp);
  }
  mint ans = 0;
  each(e, dp) ans += accumulate(e);
  wt(ans);
}
