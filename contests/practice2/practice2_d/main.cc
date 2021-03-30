#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;

  auto idx = [&](int r, int c) { return r * m + c; };
  int src = idx(n - 1, m - 1) + 1, dst = src + 1;
  atcoder::mf_graph<i32> g(dst + 1);
  auto add = [&](int u, int v) { g.add_edge(u, v, 1); };
  rep(r, n) rep(c, m) {
    if (s[r][c] == '#') continue;
    if (even(r + c)) {
      add(src, idx(r, c));
      each(nr, nc, adjacent(r, c)) {
        if (inside(nr, nc, n, m)) {
          add(idx(r, c), idx(nr, nc));
        }
      }
    } else {
      add(idx(r, c), dst);
    }
  }

  wt(g.flow(src, dst));
  each(e, g.edges()) {
    if (e.from < src && e.to < src && e.flow == 1) {
      auto ridx = [&](int i) { return make_pair(i / m, i % m); };
      auto [r, c] = ridx(e.from);
      auto [nr, nc] = ridx(e.to);
      if (c + 1 == nc) {
        s[r][c] = '>';
        s[nr][nc] = '<';
      } else if (r + 1 == nr) {
        s[r][c] = 'v';
        s[nr][nc] = '^';
      } else if (c - 1 == nc) {
        s[r][c] = '<';
        s[nr][nc] = '>';
      } else if (r - 1 == nr) {
        s[r][c] = '^';
        s[nr][nc] = 'v';
      }
    }
  }
  rep(i, n) wt(s[i]);
}
