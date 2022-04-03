#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  ints(xab, xac, xbc);
  strings(s);
  WeightedGraph<int> g(n + 6);
  int ab = n;
  int ba = n + 1;
  int ac = n + 2;
  int ca = n + 3;
  int bc = n + 4;
  int cb = n + 5;
  rep(i, n) {
    if (s[i] == 'A') {
      g[i].eb(ab, xab);
      g[i].eb(ac, xac);
      g[ba].eb(i, 0);
      g[ca].eb(i, 0);
    }
    if (s[i] == 'B') {
      g[i].eb(ba, xab);
      g[i].eb(bc, xbc);
      g[ab].eb(i, 0);
      g[cb].eb(i, 0);
    }
    if (s[i] == 'C') {
      g[i].eb(ca, xac);
      g[i].eb(cb, xbc);
      g[ac].eb(i, 0);
      g[bc].eb(i, 0);
    }
  }
  rep(m) {
    ints(a, b, c);
    g[a - 1].eb(b - 1, c);
    g[b - 1].eb(a - 1, c);
  }
  wt(*Dijkstra(g, 0).dist[n - 1]);
}
