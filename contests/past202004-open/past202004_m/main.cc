#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(d, l, n);
  V<int> c(d);
  cin >> c;
  V<int> k(n), f(n), t(n);
  rep(i, n) cin >> k[i] >> f[i] >> t[i];

  const int N = 100000;
  VV<int> vs(N + 1);
  rep(i, d) vs[c[i]].pb(i);
  V<VV<int>> dps(N + 1);
  rep(i, N + 1) {
    const V<int>& v = vs[i];
    int s = sz(v);
    // dp[i][j] = {x, y}
    // Start from j-th day and eat the favorite food 2^i times.
    // x: total times eaten
    vector dp(30, vector(s, int(0)));
    rep(j, s) {
      int curr = v[j];
      int next = (j + 1 < s) ? v[j + 1] : (v[0] + d);
      dp[0][j] = (next - curr - 1) / l + 1;
    }
    rep(j, 1, 30) rep(k, s) {
      dp[j][k] = dp[j - 1][k] + dp[j - 1][(k + (1 << (j - 1))) % s];
    }
    dps[i] = dp;
  }

  rep(i, n) {
    wt([&] {
      int ans = 0;
      int fi = f[i] - 1;
      int ti = t[i] - 1;
      const V<int>& v = vs[k[i]];
      if (v.empty()) return ans;
      int idx;
      if (c[fi] == k[i]) {
        ++ans;
        idx = lower_bound(all(v), fi) - v.begin();
      } else {
        int next;
        if (v.back() < fi) {
          idx = 0;
          next = v[0] + d;
        } else {
          auto it = lower_bound(all(v), fi);
          idx = it - v.begin();
          next = *it;
        }
        ti -= (next - fi - 1) / l;
        if (ti <= 0) return ans;
        --ti;
        ++ans;
      }
      ans += BinarySearch<int>(0, ti + 1, [&](int x) {
        const auto& dp = dps[k[i]];
        int pos = idx;
        int sum = 0;
        rrep(i, 30) {
          int y = 1 << i;
          if (y <= x) {
            x -= y;
            sum += dp[i][pos];
            pos = (pos + y) % sz(v);
          }
        }
        return sum <= ti;
      });
      return ans;
    }());
  }
}
