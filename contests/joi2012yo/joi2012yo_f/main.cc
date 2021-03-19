#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<10000>;

mint dp[2][2][3][10][10][500];

void Main() {
  strings(a, b);
  ints(m);
  auto f = [&m](const string& v) {
    int n = sz(v);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0][0][0] = 1;
    rep(i, n) {
      memset(dp[(i + 1) % 2], 0, sizeof(dp[0]));
      rep(lo, 2) rep(nz, 3) rep(d0, 10) rep(d1, 10) rep(r, m) rep(j, 10) {
        int x = v[i] - '0';
        mint y = dp[i % 2][lo][nz][d0][d1][r];
        if (y == 0) continue;
        if (!lo && j > x) continue;
        if (nz == 1 && d1 == j) continue;
        if (nz == 2) {
          assert(d0 != d1);
          if (d0 < d1 && d1 <= j) continue;
          if (d0 > d1 && d1 >= j) continue;
        }
        int nlo = lo | (j < x);
        int nnz = nz == 0 ? (j > 0) : min(2, nz + 1);
        dp[(i + 1) % 2][nlo][nnz][d1][j][(r * 10 + j) % m] += y;
      }
    }
    mint ret = 0;
    rep(i, 2) rep(j, 3) rep(k, 10) rep(l, 10) ret += dp[n % 2][i][j][k][l][0];
    return ret;
  };
  rrep(i, sz(a)) {
    --a[i];
    if (a[i] >= '0') break;
    a[i] = '9';
  }
  wt(f(b) - f(a));
}
