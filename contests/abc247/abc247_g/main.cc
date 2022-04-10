#include <bits/stdc++.h>
#include <min_cost_flow.h>

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
  V<pair<int, int>> slope = InterpolateSlope(g.slope(s, t));
  wt(sz(slope) - 1);
  rep(i, 1, sz(slope)) {
    auto [cap, cost] = slope[i];
    wt(cap * big - cost);
  }
}
