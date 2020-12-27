#include <bits/stdc++.h>

#include "atcoder.h"
#undef int
#include "bignum.h"
#define int i64

using ld = decfloat;
using Matrix = VV<ld>;

Matrix Mult(const Matrix& a, const Matrix& b) {
  int h = sz(a), w = sz(b[0]);
  Matrix c(h, V<ld>(w));
  rep(i, h) rep(j, w) rep(k, sz(a[0])) c[i][j] += a[i][k] * b[k][j];
  return c;
}

Matrix Pow(const Matrix& m, int p) {
  if (p == 0) {
    return {{1, 0}, {0, 1}};
  }
  if (p % 2 == 0) {
    Matrix n = Pow(m, p / 2);
    return Mult(n, n);
  }
  return Mult(Pow(m, p - 1), m);
}

void Main() {
  rd(ld, p);
  ints(n);
  Matrix m = {{1 - p, p}, {p, 1 - p}};
  m = Pow(m, n);
  wt(m[1][0]);
}
