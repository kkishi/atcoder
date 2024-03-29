#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  mint ans = 0;
  map<int, int> mp;
  each(e, a) each(f, e)++ mp[--f];
  V<bool> sm(n * n);
  each(k, v, mp) if (v >= n) {
    vector dp(n, vector(n, mint(0)));
    rep(i, n) rep(j, n) {
      if (a[i][j] == k) {
        ++dp[i][j];
        ans += dp[i][j];
      }
      if (i + 1 < n) dp[i + 1][j] += dp[i][j];
      if (j + 1 < n) dp[i][j + 1] += dp[i][j];
    }
  }
  else {
    sm[k] = true;
  }
  VV<pair<int, int>> v(n * n);
  rep(i, n) rep(j, n) if (sm[a[i][j]]) v[a[i][j]].eb(i, j);
  each(e, v) {
    rep(j, sz(e)) rep(i, j + 1) {
      int x = e[j].first - e[i].first;
      int y = e[j].second - e[i].second;
      if (y >= 0) ans += mint::Comb(x + y, x);
    }
  }
  wt(ans);
}
