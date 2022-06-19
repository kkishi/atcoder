#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, d);
  mint ans = 0;
  rep(i, d + 2) {
    rep(v0, 2) {
      using V = Matrix<mint, 2, 1>;
      V x = {};
      x[v0][0] = 1;
      using M = Matrix<mint, 2, 2>;
      M a = {};
      a[0][0] = mint::Comb(d - 1, i);
      a[0][1] = mint::Comb(d - 1, i - 1);
      a[1][0] = mint::Comb(d - 1, i - 1);
      a[1][1] = mint::Comb(d - 1, i - 2);
      M b = Pow(a, n);
      V y = Mult(b, x);
      ans += y[v0][0];
    }
  }
  wt(ans);
}
