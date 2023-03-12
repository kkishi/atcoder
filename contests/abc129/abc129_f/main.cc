#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"
#include "matrix.h"

using mint = atcoder::modint;

void Main() {
  ints(l, a, b, m);
  mint::set_mod(m);
  int ten = 1;
  int rem = l;
  mint ans = 0;
  rep(20) {
    ten *= 10;

    // Count the number of elements with ten-1 digits.
    int lo = div_ceil(ten / 10 - a, b);  // ten/10 <= a+b*lo
    chmax(lo, 0);
    int hi = div_ceil(ten - a, b);  // ten <= a+b*hi
    int cnt = hi - lo;
    chmin(cnt, rem);
    if (cnt <= 0) continue;
    rem -= cnt;

    using M = Matrix<mint, 3, 3>;
    M mat = {{
        {ten, 1, 0},
        {0, 1, b},
        {0, 0, 1},
    }};
    using V = Matrix<mint, 3, 1>;
    V ini = {{
        {ans},
        {a + b * lo},
        {1},
    }};
    V res = Mult(Pow(mat, cnt), ini);
    ans = res[0][0];
  }
  wt(ans.val());
}
