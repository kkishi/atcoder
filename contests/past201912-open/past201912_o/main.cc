#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"

void Main() {
  ints(n);
  vector a(n, vector(6, int(0)));
  rep(i, n) rep(j, 6) cin >> a[i][j];

  V<int> v;
  rep(i, n) rep(j, 6) v.pb(a[i][j]);
  Compressor c(v);

  VV<int> idx(sz(c.coord));
  rep(i, n) rep(j, 6) idx[c(a[i][j])].pb(i);

  V<double> dice(n);
  set<pair<double, int>> s;

  V<double> dp(sz(c.coord));
  rrep(i, sz(c.coord)) {
    dp[i] = 1 + (s.empty() ? 0 : prev(s.end())->first);
    for (int j : idx[i]) {
      auto it = s.find({dice[j], j});
      if (it != s.end()) s.erase(it);
      dice[j] += dp[i] / 6;
      s.insert({dice[j], j});
    }
  }

  double ans = 0;
  rep(i, n) {
    double x = 0;
    rep(j, 6) x += dp[c(a[i][j])];
    chmax(ans, 1 + x / 6);
  }
  wt(ans);
}
