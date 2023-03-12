#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "matrix.h"

using mint = atcoder::modint;

void Main() {
  ints(a, x, m);
  mint::set_mod(m);
  using M = Matrix<mint, 2, 2>;
  M mat = {{{mint(a), 1}, {0, 1}}};
  using V = Matrix<mint, 2, 1>;
  V ini = {{{0}, {1}}};
  V ans = Mult(Pow(mat, x), ini);
  wt(ans[0][0].val());
}
