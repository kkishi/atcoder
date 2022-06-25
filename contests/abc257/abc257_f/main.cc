#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  V<bool> open(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    if (u == -1) {
      open[v] = true;
    } else {
      g[u].eb(v, 1);
      g[v].eb(u, 1);
    }
  }
  auto S = Dijkstra(g, 0).dist;
  auto T = Dijkstra(g, n - 1).dist;
  int su = big;
  rep(i, n) if (S[i] && open[i]) chmin(su, *S[i]);
  int tu = big;
  rep(i, n) if (T[i] && open[i]) chmin(tu, *T[i]);
  int sut = big;
  if (su < big && tu < big) sut = su + 2 + tu;
  if (S[n - 1]) chmin(sut, *S[n - 1]);
  V<int> v;
  rep(i, n) {
    int ans = sut;
    if (S[i]) chmin(ans, *S[i] + 1 + tu);
    if (T[i]) chmin(ans, su + 1 + *T[i]);
    if (ans == big) {
      v.eb(-1);
    } else {
      v.eb(ans);
    }
  }
  wt(v);
}
