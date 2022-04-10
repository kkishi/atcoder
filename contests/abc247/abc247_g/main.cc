#include <bits/stdc++.h>

#include <atcoder/mincostflow>

#include "atcoder.h"

void Main() {
  ints(n);
#define prog(i) (i)
#define univ(i) (prog(n) + (i))
#define good(i) (univ(150) + (i))
  int s = good(150), t = s + 1;
  atcoder::mcf_graph<int, int> g(t + 1);
  rep(i, 150) g.add_edge(s, univ(i), 1, 0);
  rep(i, 150) g.add_edge(good(i), t, 1, 0);
  const int big = 1000000000;
  rep(i, n) {
    ints(a, b, c);
    --a, --b;
    g.add_edge(univ(a), prog(i), 1, big - c);
    g.add_edge(prog(i), good(b), 1, 0);
  }
  V<pair<int, int>> slope = g.slope(s, t);
  int k = slope.back().first;
  wt(k);
  rep(i, sz(slope) - 1) {
    auto [x0, y0] = slope[i];
    auto [x1, y1] = slope[i + 1];
    rep(x, x0 + 1, x1 + 1) {
      wt(x * big - (y0 + (y1 - y0) / (x1 - x0) * (x - x0)));
    }
  }
}
