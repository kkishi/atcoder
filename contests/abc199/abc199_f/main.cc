#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<>;
using M = Matrix<mint, 100, 100>;
using N = Matrix<mint, 100, 1>;

void Main() {
  ints(n, m, k);
  V<int> a(n);
  cin >> a;
  mint c = mint(1) / (2 * m);
  M A{};
  rep(i, n) A[i][i] = 1;
  rep(m) {
    ints(x, y);
    --x, --y;
    A[x][x] -= c;
    A[x][y] += c;
    A[y][y] -= c;
    A[y][x] += c;
  }
  M B = Pow(A, k);
  N X{};
  rep(i, n) X[i][0] = a[i];
  N ans = Mult(B, X);
  rep(i, n) wt(ans[i][0]);
}
