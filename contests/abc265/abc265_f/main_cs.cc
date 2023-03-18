#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

template <typename T>
void CumulativeSum(VV<T>& v, int dr, int dc) {
  int h = sz(v), w = sz(v[0]);
  int r_begin = 0, r_end = h, r_inc = 1;
  if (dr < 0) r_begin = h - 1, r_end = -1, r_inc = -1;
  int c_begin = 0, c_end = w, c_inc = 1;
  if (dc < 0) r_begin = w - 1, c_end = -1, c_inc = -1;
  for (int r = r_begin; r != r_end; r += r_inc) {
    for (int c = c_begin; c != c_end; c += c_inc) {
      if (inside(r + dr, c + dc, h, w)) {
        v[r + dr][c + dc] += v[r][c];
      }
    }
  }
}

void Main() {
  ints(n, d);
  V<int> p(n), q(n);
  cin >> p >> q;
  vector dp(d + 1, vector(d + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    const int s = abs(p[i] - q[i]);
    vector ndp0(d + 1, vector(d + 1, mint(0)));
    vector ndp1(d + 1, vector(d + 1, mint(0)));
    rep(j, d + 1) rep(k, d + 1) {
      if (dp[j][k] == 0) continue;
      if (j + s <= d) ndp0[j + s][k] += dp[j][k];
      if (j + 1 <= d && k + s + 1 <= d) ndp0[j + 1][k + s + 1] += dp[j][k];
      if (s > 0) {
        {
          int r = min(j + s - 1, d);
          int c = k + (j + s - r);
          if (inside(r, c, d + 1, d + 1)) ndp1[r][c] += dp[j][k];
        }
        {
          int c = k + s + 1;
          int r = j - 1;
          if (inside(r, c, d + 1, d + 1)) ndp1[r][c] -= dp[j][k];
        }
      }
    }
    CumulativeSum(ndp0, 1, 1);
    CumulativeSum(ndp1, -1, 1);
    rep(j, d + 1) rep(k, d + 1) dp[j][k] = ndp0[j][k] + ndp1[j][k];
  }
  mint ans = 0;
  each(e, dp) ans += accumulate(e);
  wt(ans);
}
