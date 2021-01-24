#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"

using mat = Matrix<int, 2, 2>;
using vec = Matrix<int, 2, 1>;

void Main() {
  ints(n);
  V<vec> P;
  rep(n) {
    ints(x, y);
    P.pb({{{x}, {y}}});
  }
  ints(m);
  V<vec> C(m + 1);
  C[0] = {{{0}, {0}}};
  V<mat> A(m + 1);
  A[0] = {{{1, 0}, {0, 1}}};
  rep(i, m) {
    ints(k);
    if (k == 1) {
      mat x = {{{0, 1}, {-1, 0}}};
      A[i + 1] = Mult(x, A[i]);
      C[i + 1] = Mult(x, C[i]);
    } else if (k == 2) {
      mat x = {{{0, -1}, {1, 0}}};
      A[i + 1] = Mult(x, A[i]);
      C[i + 1] = Mult(x, C[i]);
    } else {
      ints(p);
      if (k == 3) {
        C[i + 1] = {{{2 * p - C[i][0][0]}, {C[i][1][0]}}};
        A[i + 1] = Mult(mat{{{-1, 0}, {0, 1}}}, A[i]);
      } else {
        C[i + 1] = {{{C[i][0][0]}, {2 * p - C[i][1][0]}}};
        A[i + 1] = Mult(mat{{{1, 0}, {0, -1}}}, A[i]);
      }
    }
  }
  ints(q);
  rep(q) {
    ints(a, b);
    vec ans = Plus(Mult(A[a], P[b - 1]), C[a]);
    wt(ans[0][0], ans[1][0]);
  }
}
