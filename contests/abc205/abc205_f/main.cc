#include <bits/stdc++.h>

#include <atcoder/maxflow>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
#define token_i(i) (i)
#define token_o(i) (token_i(n) + (i))
#define row(r) (token_o(n) + (r))
#define col(c) (row(h) + (c))
  int s = col(w);
  int t = s + 1;
  atcoder::mf_graph<int> g(t + 1);
#define add(i, j) g.add_edge(i, j, 1)
  rep(r, h) add(s, row(r));
  rep(i, n) {
    ints(a, b, c, d);
    rep(r, a - 1, c) add(row(r), token_i(i));
    add(token_i(i), token_o(i));
    rep(c, b - 1, d) add(token_o(i), col(c));
  }
  rep(c, w) add(col(c), t);
  wt(g.flow(s, t));
}
