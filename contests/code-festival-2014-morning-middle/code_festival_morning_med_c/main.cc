#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#undef int
#include "bignum.h"
#define int i64

void Main() {
  rd(decfloat, p);
  ints(n);
  Matrix<decfloat, 2, 2> m{{{1 - p, p}, {p, 1 - p}}};
  wt(Pow(m, n)[1][0]);
}
