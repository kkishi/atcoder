#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(n);
  ints(m);
  V<int> c(m);
  cin >> c;
  V<int> rc(10, 0);
  rep(i, m) rc[c[i]] = 1 << i;
  int N = sz(n);
  using A = array<mint, 2>;
  vector dp(N + 1, vector(2, vector(2, vector(1 << m, A()))));
  dp[0][0][0][0] = {1, 0};
  rep(i, N) rep(lo, 2) rep(nz, 2) rep(mask, 1 << m) {
    A d = dp[i][lo][nz][mask];
    if (d[0] == 0) continue;
    rep(j, 10) {
      int x = n[i] - '0';
      if (!lo && j > x) continue;
      int nlo = lo | (j < x);
      int nnz = nz | (j > 0);
      int nmask = mask;
      if (nz || j > 0) nmask |= rc[j];
      auto& e = dp[i + 1][nlo][nnz][nmask];
      e[0] += d[0];
      e[1] += d[1] * 10 + j * d[0];
    }
  }
  mint ans = 0;
  rep(i, 2) ans += dp[N][i][1][(1 << m) - 1][1];
  wt(ans);
}
