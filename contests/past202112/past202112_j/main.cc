#include <bits/stdc++.h>
// #include <cassert>

#include "atcoder.h"

void Main() {
  ints(n, q);
  vector v(n, vector(n, false));
  using P = pair<int, int>;
  V<P> coord = {{0, 0}, {0, n - 1}, {n - 1, 0}, {n - 1, n - 1}};
  auto rot90 = [&](P& p) { p = {p.second, n - 1 - p.first}; };
  auto conv = [&](int x, int y) {
    V<P> c = coord;
    int cnt = 0;
    P p = {x, y};
    while (c[0] != P{0, 0}) {
      ++cnt;
      each(e, c) rot90(e);
      rot90(p);
    }
    // dbg(cnt, c);
    // P p = {x, y};
    if (c[1] != P{0, n - 1}) {
      swap(p.first, p.second);
      // dbg(cnt);
      /*
      if (even(cnt)) {
        swap(p.first, p.second);
      } else {
        p = P{n - 1 - p.first, n - 1 - p.second};
      }
      */
    }
    // rep(cnt) rot90(p);
    return p;
  };
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(x, y);
      P p = conv(x - 1, y - 1);
      v[p.first][p.second] = !v[p.first][p.second];
      dbg(x - 1, y - 1, p);
    } else {
      rd(char, c);
      dbg(k, c);
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
#ifdef DEBUG
    V<string> w(n, string(n, '.'));
    rep(i, 4) w[coord[i].first][coord[i].second] = i + 'A';
    each(e, w) dbg(e);
    dbg(conv(0, 0));
    dbg(conv(0, 2));

    V<string> ans(n, string(n, '0'));
    rep(i, n) rep(j, n) {
      P p = conv(i, j);
      if (v[p.first][p.second]) ans[i][j] = '1';
    }
    each(e, ans) dbg(e);

    rep(i, n) {
      string s;
      rep(j, n) s += (v[i][j] ? '#' : '.');
      dbg(s);
    }
#endif
  }
  V<string> ans(n, string(n, '0'));
  rep(i, n) rep(j, n) {
    P p = conv(i, j);
    if (v[p.first][p.second]) ans[i][j] = '1';
  }
  each(e, ans) wt(e);
}
