#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "dijkstra.h"
#include "graph.h"

int mod(int x, int m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}

void Main() {
  ints(n, m);
  V<int> a(n), b(n);
  cin >> a >> b;
  each(e, a) e = mod(m - e, m);
  each(e, b) e = mod(e, m);

  V<int> ab;
  each(e, a) ab.eb(e);
  each(e, b) ab.eb(e);
  Compressor c(ab);

  int N = sz(c.coord);
  Graph<int> g(n + N);
  rep(i, N) {
    int j = (i + 1) % N;
    g.AddEdge(n + i, n + j, mod(c.coord[j] - c.coord[i], m));
  }
  rep(i, n) {
    g.AddEdge(i, n + c(a[i]), 0);
    g.AddEdge(n + c(b[i]), i, 0);
  }
  wt(*Dijkstra(g, 0).dist[n - 1]);
}
