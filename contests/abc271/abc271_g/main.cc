#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<998244353>;

using M = Matrix<mint, 24, 24>;
using N = Matrix<mint, 24, 1>;

void Main() {
  ints(n, x, y);
  strings(c);
  N a = {};
  a[23][0] = 1;
  M A = {};
  V<mint> p(24);
  rep(i, 24) p[i] = mint(c[i] == 'T' ? x : y) / 100;
  mint X = 1;
  rep(i, 24) X *= 1 - p[i];
  rep(i, 24) {
    mint Y = 1;
    rrep(j, 24) {
      int J = (i + j) % 24;
      A[i][J] = 1 / (1 - X) * p[i] * Y;
      Y *= 1 - p[J];
    }
  }
  M B = Pow(A, n);
  N C = Mult(B, a);
  mint ans = 0;
  rep(i, 24) if (c[i] == 'A') ans += C[i][0];
  wt(ans);
}
