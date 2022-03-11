#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, m);
  V<int> w(n);
  cin >> w;
  V<int> l(m), v(m);
  rep(i, m) cin >> l[i] >> v[i];

  rep(i, n) rep(j, m) if (w[i] > v[j]) {
    wt(-1);
    return;
  }

  V<pair<int, int>> s;
  rep(i, m) s.eb(v[i], l[i]);
  sort(all(s));
  rep(i, sz(s) - 1) chmax(s[i + 1].second, s[i].second);
  auto lookup = [&s](int x) {
    auto it = lower_bound(all(s), pair<int, int>{x, 0});
    return it == s.begin() ? 0 : prev(it)->second;
  };

  sort(all(w));
  int ans = big;
  do {
    CumulativeSum1D sum(w);
    vector dist(n, vector(n, 0));
    rep(i, n - 1) rep(j, i + 1, n) dist[i][j] = lookup(sum.Get(i, j));
    V<int> dp(n);
    rep(i, 1, n) rep(j, i) chmax(dp[i], dp[j] + dist[j][i]);
    chmin(ans, dp[n - 1]);
  } while (next_permutation(all(w)));
  wt(ans);
}
