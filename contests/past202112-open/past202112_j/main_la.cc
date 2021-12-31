#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"

void Main() {
  ints(n, q);
  map<pair<int, int>, int> mp;
  using M = Matrix<int, 2, 2>;
  using A = Matrix<int, 2, 1>;
  M m = {{{1, 0}, {0, 1}}};
  auto get = [&](int x, int y) -> int& {
    if (even(n)) {
      x = x * 2 - n + 1;
      y = y * 2 - n + 1;
    } else {
      x = x - n / 2;
      y = y - n / 2;
    }
    A p = {{{x}, {y}}};
    p = Mult(m, p);
    x = p[0][0];
    y = p[1][0];
    return mp[{x, y}];
  };
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(x, y);
      --x, --y;
      get(x, y) = 1 - get(x, y);
    } else {
      rd(char, c);
      m = Mult(
          m, k == 2 ? (c == 'A' ? M{{{0, -1}, {1, 0}}} : M{{{0, 1}, {-1, 0}}})
                    : (c == 'A' ? M{{{-1, 0}, {0, 1}}} : M{{{1, 0}, {0, -1}}}));
    }
  }
  V<string> ans(n, string(n, '0'));
  rep(i, n) rep(j, n) ans[i][j] += get(i, j);
  each(e, ans) wt(e);
}
