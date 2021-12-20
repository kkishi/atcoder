#include <bits/stdc++.h>

#include <atcoder/mincostflow>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  atcoder::mcf_graph<int, int> g(h + w + 4);
  int s = h + w, t = s + 1, S = t + 1, T = S + 1;

  rep(i, h) g.add_edge(s, i, big, 0);
  rep(i, w) g.add_edge(h + i, t, big, 0);
  rep(n) {
    ints(a, b, c);
    --a, --b;
    g.add_edge(a, h + b, 1, c);
  }
  g.add_edge(t, s, big, 0);

  rep(i, h) g.add_edge(S, i, 1, 0);
  rep(i, w) g.add_edge(h + i, T, 1, 0);
  g.add_edge(s, T, h, 0);
  g.add_edge(S, t, w, 0);

  wt(g.flow(S, T).second);
}
