#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, W);
  V<int> v(N), w(N);
  rep(i, N) cin >> v[i] >> w[i];
  if (N <= 30) {
    V<pair<int, int>> cand;
    int n = N / 2;
    rep(i, 1 << n) {
      int vs = 0, ws = 0;
      rep(j, n) if (hasbit(i, j)) {
        vs += v[j];
        ws += w[j];
      }
      cand.pb({ws, vs});
    }
    sort(cand);
    rep(i, 1, sz(cand)) chmax(cand[i].second, cand[i - 1].second);
    reverse(cand);
    int ans = 0;
    rep(i, 1 << (N - n)) {
      int vs = 0, ws = 0;
      rep(j, (N - n)) if (hasbit(i, j)) {
        vs += v[j + n];
        ws += w[j + n];
      }
      auto it = lower_bound(all(cand), pair<int, int>{W - ws, vs}, greater());
      if (it != cand.end()) chmax(ans, vs + it->second);
    }
    wt(ans);
  } else if (int mw = max(w); mw <= 1000) {
    int size = min(W, N * mw);
    V<int> dp(size + 1, -1);
    dp[0] = 0;
    rep(i, N) rrep(j, size + 1 - w[i]) if (dp[j] != -1) {
      chmax(dp[j + w[i]], dp[j] + v[i]);
    }
    wt(max(dp));
  } else {
    int mv = max(v);
    assert(mv <= 1000);
    int size = N * mv;
    V<int> dp(size + 1, big);
    dp[0] = 0;
    rep(i, N) rrep(j, size + 1 - v[i]) if (dp[j] != big) {
      chmin(dp[j + v[i]], dp[j] + w[i]);
    }
    int ans = 0;
    rep(i, sz(dp)) if (dp[i] <= W) chmax(ans, i);
    wt(ans);
  }
}
