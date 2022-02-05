#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> p(n), q(n);
  cin >> p >> q;
  V<pair<int, int>> v;
  vector g(n, vector(n, int(0)));
  rep(i, n) {
    --p[i], --q[i];
    v.eb(p[i], q[i]);
    g[p[i]][q[i]] = 1;
  }
  vector s(n + 1, vector(n + 1, int(0)));
  rep(i, n) rep(j, n) {
    s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + g[i][j];
  }
  sort(all(v));
  vector dp(n, vector(n + 1, mint(0)));
  rep(i, n) {
    auto [p1, q1] = v[i];
    int cnt = s[p1 + 1][q1 + 1];
    dp[i][cnt] += 1;
    rep(j, i) {
      auto [p0, q0] = v[j];
      if (p0 < p1 && q0 > q1) {
        rep(k, n + 1) {
          int y = k + cnt - s[p0 + 1][q1 + 1];
          dp[i][y] += dp[j][k];
        }
      }
    }
  }
  mint ans = 0;
  rep(i, n) ans += dp[i][k];
  wt(ans);
}
