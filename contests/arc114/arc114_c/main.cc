#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);

  V<mint> p(n + 1);
  p[0] = 1;
  rep(i, n) p[i + 1] = p[i] * m;

  vector L(n + 1, vector(2, mint(0)));
  vector R(n + 1, mint(0));

  mint sum = 0;
  rep(M, 1, m + 1) {
    L[0][0] = 1;
    L[0][1] = 0;
    rep(i, n) {
      L[i + 1][0] = L[i][0] * (m - 1) + L[i][1] * (M - 1);
      L[i + 1][1] = L[i][0] + L[i][1] * (m - M + 1);
    }
    R[0] = 0;
    rep(i, n) R[i + 1] = R[i] * (m - M + 1) + p[i];
    rep(i, n - 1) sum += (p[i] - L[i][1]) * R[n - 1 - i];
  }
  wt(p[n] * n - sum);
}
