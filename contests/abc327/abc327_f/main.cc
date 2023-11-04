#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "atcoder.h"

void Main() {
  ints(n, d, w);
  map<int, V<pair<int, int>>> events;
  rep(n) {
    ints(t, x);
    events[t].eb(x, 1);
    events[t + d].eb(x, -1);
  }
  int N = 200000;
  add_max::segtree tree(V<int>(N + 1, 0));
  int ans = 0;
  each(t, es, events) {
    each(x, v, es) tree.apply(max(x - w, 0), x, v);
    chmax(ans, tree.prod(0, N + 1));
  }
  wt(ans);
}
