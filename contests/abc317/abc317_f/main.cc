#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(3);
  cin >> a;

  V<int> v;
  while (n) {
    v.eb(n & 1);
    n >>= 1;
  }
  reverse(v);
  int N = sz(v);

  vector dp(
      N + 1,
      vector(
          2,
          vector(
              2,
              vector(
                  10,
                  vector(
                      2,
                      vector(
                          2,
                          vector(
                              10,
                              vector(2, vector(2, vector(10, mint(0)))))))))));
  dp[0][0][0][0][0][0][0][0][0][0] = 1;
  rep(i, N) rep(l0, 2) rep(o0, 2) rep(m0, a[0]) rep(l1, 2) rep(o1, 2)
      rep(m1, a[1]) rep(l2, 2) rep(o2, 2) rep(m2, a[2]) {
    rep(b0, 2) rep(b1, 2) rep(b2, 2) {
      if (b0 ^ b1 ^ b2) continue;
      if (!l0 && (v[i] < b0)) continue;
      if (!l1 && (v[i] < b1)) continue;
      if (!l2 && (v[i] < b2)) continue;
      int nl0 = l0 | (v[i] > b0);
      int nl1 = l1 | (v[i] > b1);
      int nl2 = l2 | (v[i] > b2);
      int no0 = o0 | b0;
      int no1 = o1 | b1;
      int no2 = o2 | b2;
      int nm0 = ((m0 << 1) | b0) % a[0];
      int nm1 = ((m1 << 1) | b1) % a[1];
      int nm2 = ((m2 << 1) | b2) % a[2];
      dp[i + 1][nl0][no0][nm0][nl1][no1][nm1][nl2][no2][nm2] +=
          dp[i][l0][o0][m0][l1][o1][m1][l2][o2][m2];
    }
  }
  mint ans = 0;
  rep(l0, 2) rep(l1, 2) rep(l2, 2) ans += dp[N][l0][1][0][l1][1][0][l2][1][0];
  wt(ans);
}
