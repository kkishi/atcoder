#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"

using mat = Matrix<int, 3, 3>;
using vec = Matrix<int, 3, 1>;

void Main() {
  ints(n);
  V<vec> P;
  rep(n) {
    ints(x, y);
    P.pb({{{x}, {y}, {1}}});
  }
  ints(m);
  V<mat> A(m + 1);
  A[0] = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
  rep(i, m) {
    mat a = []() -> mat {
      ints(k);
      if (k == 1) return {{{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}};
      if (k == 2) return {{{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}};
      ints(p);
      if (k == 3) return {{{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}}};
      assert(k == 4);
      return {{{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}}};
    }();
    A[i + 1] = Mult(a, A[i]);
  }
  ints(q);
  rep(i, q) {
    ints(a, b);
    vec ans = Mult(A[a], P[b - 1]);
    wt(ans[0][0], ans[1][0]);
  }
}
