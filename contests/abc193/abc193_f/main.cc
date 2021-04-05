#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

#define adjacent_inside(ni, nj, i, j, I, J) \
  for (auto [ni, nj] : adjacent(i, j))      \
    if (inside(ni, nj, I, J))

void Main() {
  ints(n);
  V<string> c(n);
  cin >> c;

  int w = 0, b = 1;
  auto idx = [&](int i, int j) { return (b + 1) + (i * n + j); };
  atcoder::mf_graph<int> g(idx(n - 1, n - 1) + 1);
  int tot = n * (n - 1) * 2;
  rep(i, n) rep(j, n) {
    if (char d = c[i][j]; d != '?') {
      if (i + 1 < n && c[i + 1][j] == d) --tot;
      if (j + 1 < n && c[i][j + 1] == d) --tot;
      continue;
    }
    int x = idx(i, j);
    bool flip = !even(i + j);
    adjacent_inside(ni, nj, i, j, n, n) {
      int y = idx(ni, nj);
      char d = c[ni][nj];
      if (d == '?') {
        g.add_edge(x, y, 1);
      } else if ((d == 'W') ^ flip) {
        g.add_edge(w, x, 1);
      } else {
        g.add_edge(x, b, 1);
      }
    }
  }
  wt(tot - g.flow(w, b));
}
