#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "disjoint_set.h"

void Main() {
  ints(n);
  V<pair<int, int>> v(n);
  cin >> v;
  V<int> w;
  w.eb(1);
  each(a, b, v) {
    w.eb(a);
    w.eb(b);
  }
  Compressor c(w);
  int N = sz(c.coord);
  DisjointSet ds(N);
  each(a, b, v) ds.Union(c(a), c(b));
  int ans = 0;
  rep(i, N) if (ds.Same(0, i)) chmax(ans, c.coord[i]);
  wt(ans);
}
