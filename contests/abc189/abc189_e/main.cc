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
  V<int> k(m), p(m);
  rep(i, m) {
    cin >> k[i];
    if (k[i] >= 3) cin >> p[i];
  }
  ints(q);
  VV<pair<int, int>> ab(m + 1);
  rep(i, q) {
    ints(a, b);
    ab[a].pb({i, b - 1});
  }

  vec C = {{{0}, {0}}};
  mat A = {{{1, 0}, {0, 1}}};
  V<vec> ans(q);
  rep(i, m + 1) {
    each(j, b, ab[i]) ans[j] = Plus(Mult(A, P[b]), C);
    if (i == m) break;
    if (k[i] == 1) {
      mat x = {{{0, 1}, {-1, 0}}};
      A = Mult(x, A);
      C = Mult(x, C);
    }
    if (k[i] == 2) {
      mat x = {{{0, -1}, {1, 0}}};
      A = Mult(x, A);
      C = Mult(x, C);
    }
    if (k[i] == 3) {
      C[0][0] = 2 * p[i] - C[0][0];
      A = Mult(mat{{{-1, 0}, {0, 1}}}, A);
    }
    if (k[i] == 4) {
      C[1][0] = 2 * p[i] - C[1][0];
      A = Mult(mat{{{1, 0}, {0, -1}}}, A);
    }
  }
  rep(i, q) wt(ans[i][0][0], ans[i][1][0]);
}
