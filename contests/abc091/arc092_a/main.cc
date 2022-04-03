#include <bits/stdc++.h>

#include "atcoder.h"
#include "edmonds_karp.h"
#include "graph.h"

struct XY {
  int x, y;
};

void Main() {
  ints(n);
  WeightedGraph<int> g(n * 2 + 2);
  V<XY> r(n), b(n);
  rep(i, n) cin >> r[i].x >> r[i].y;
  rep(i, n) cin >> b[i].x >> b[i].y;
  const int r0 = 0, b0 = r0 + n, s = b0 + n, d = s + 1;
  auto add = [&](int i, int j) {
    g[i].eb(j, 1);
    g[j].eb(i, 0);
  };
  rep(i, n) add(s, r0 + i);
  rep(i, n) add(b0 + i, d);
  rep(i, n) rep(j, n) if (r[i].x < b[j].x && r[i].y < b[j].y)
      add(r0 + i, b0 + j);
  wt(EdmondsKarp(g, s, d));
}
