#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  vector v(n, vector(n, '0'));
  using P = pair<int, int>;
  V<P> coord = {{0, 0}, {0, n - 1}, {n - 1, 0}, {n - 1, n - 1}};
  auto rot90 = [&](P& p) { p = {p.second, n - 1 - p.first}; };
  auto get = [&](int x, int y) -> char& {
    V<P> c = coord;
    P p = {x, y};
    while (c[0] != P{0, 0}) {
      each(e, c) rot90(e);
      rot90(p);
    }
    if (c[1] != P{0, n - 1}) {
      swap(p.first, p.second);
    }
    return v[p.first][p.second];
  };
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(x, y);
      --x, --y;
      get(x, y) = ('0' + '1') - get(x, y);
    } else {
      rd(char, c);
      if (k == 2) {
        if (c == 'A') {
          each(e, coord) rot90(e);
        } else {
          each(e, coord) rep(3) rot90(e);
        }
      } else {
        if (c == 'A') {
          each(e, coord) e.first = n - 1 - e.first;
        } else {
          each(e, coord) e.second = n - 1 - e.second;
        }
      }
    }
  }
  V<string> ans(n, string(n, '0'));
  rep(i, n) rep(j, n) ans[i][j] = get(i, j);
  each(e, ans) wt(e);
}
