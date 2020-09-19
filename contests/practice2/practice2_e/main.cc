#include <bits/stdc++.h>

#include <atcoder/mincostflow>

#include "atcoder.h"

void Main() {
  ints(n, k);
  VV<int> a(n, V<int>(n));
  cin >> a;

  int s = n * 2, d = s + 1;
  atcoder::mcf_graph<int, int> g(d + 1);
  rep(i, n) g.add_edge(s, i, k, 0);
  rep(i, n) g.add_edge(n + i, d, k, 0);
  const int big = 1'000'000'000LL;
  VV<int> e(n, V<int>(n));
  rep(i, n) rep(j, n) e[i][j] = g.add_edge(i, n + j, 1, big - a[i][j]);
  g.add_edge(s, d, n * k, big);

  auto [cap, cost] = g.flow(s, d, n * k);
  wt(cap * big - cost);
  rep(i, n) {
    rep(j, n) cout << (g.get_edge(e[i][j]).flow ? 'X' : '.');
    cout << endl;
  }
}
