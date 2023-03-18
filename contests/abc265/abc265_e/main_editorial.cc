#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  ints(a, b, c, d, e, f);
  set<pair<int, int>> st;
  rep(m) {
    ints(x, y);
    st.insert({x, y});
  }
  vector dp(n + 1, vector(n + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    vector ndp(n + 1, vector(n + 1, mint(0)));
    rep(j, i + 1) rep(k, i - j + 1) {
      int l = i - (j + k);
      int x = a * j + c * k + e * l;
      int y = b * j + d * k + f * l;
      if (!st.count({x + a, y + b})) ndp[j + 1][k] += dp[j][k];
      if (!st.count({x + c, y + d})) ndp[j][k + 1] += dp[j][k];
      if (!st.count({x + e, y + f})) ndp[j][k] += dp[j][k];
    }
    swap(dp, ndp);
  }
  mint ans = 0;
  each(e, dp) each(e, e) ans += e;
  wt(ans);
}
