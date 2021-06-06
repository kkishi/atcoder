#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<998244353>;
using M = Matrix<mint, 64, 64>;
using N = Matrix<mint, 64, 1>;

void Main() {
  ints(h, w);
  M A{};
  rep(mask, 1 << h) {
    Fix([&](auto rec, int depth, int mask2) {
      if (depth == h) {
        ++A[mask][mask2];
        return;
      }
      if (hasbit(mask, depth)) {
        rec(depth + 1, mask2);
      } else {
        rec(depth + 1, mask2);
        rec(depth + 1, mask2 | (1 << depth));
        if (depth + 1 < h && !hasbit(mask, depth + 1)) {
          rec(depth + 2, mask2);
        }
      }
    })(0, 0);
  }
  N X{};
  X[0][0] = 1;
  N Y = Mult(Pow(A, w), X);
  wt(Y[0][0]);
}
