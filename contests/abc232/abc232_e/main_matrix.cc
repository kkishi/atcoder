#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<998244353>;
using mat = Matrix<mint, 4, 4>;
using vec = Matrix<mint, 4, 1>;

void Main() {
  ints(h, w, k);
  ints(x1, y1, x2, y2);
  mat x = {{{h - 2 + w - 2, w - 1, h - 1, 0},
            {1, h - 2, 0, h - 1},
            {1, 0, w - 2, w - 1},
            {0, 1, 1, 0}}};
  vec a = {};
  a[(x1 == x2) * 2 + (y1 == y2)][0] = 1;
  wt(Mult(Pow(x, k), a)[3][0]);
}
