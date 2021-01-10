#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

using namespace atcoder;

void Main() {
  ints(n);
  int m = 400000;
  mf_graph<int> g(m + n + 2);
  auto value = [&](int idx) { return idx; };
  auto card = [&](int idx) { return value(m) + idx; };
  int src = card(n);
  int dst = src + 1;
  rep(i, m) g.add_edge(value(i), dst, 1);
  rep(i, n) g.add_edge(src, card(i), 1);
  rep(i, n) {
    ints(a, b);
    g.add_edge(card(i), value(a - 1), 1);
    g.add_edge(card(i), value(b - 1), 1);
  }
  wt(g.flow(src, dst));
}
