#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main() {
  ints(n, m);
  ints(xab, xac, xbc);
  strings(s);
  Graph<int> g(n + 6);
  int ab = n;
  int ba = n + 1;
  int ac = n + 2;
  int ca = n + 3;
  int bc = n + 4;
  int cb = n + 5;
  rep(i, n) {
    if (s[i] == 'A') {
      g.AddEdge(i, ab, xab);
      g.AddEdge(i, ac, xac);
      g.AddEdge(ba, i);
      g.AddEdge(ca, i);
    }
    if (s[i] == 'B') {
      g.AddEdge(i, ba, xab);
      g.AddEdge(i, bc, xbc);
      g.AddEdge(ab, i);
      g.AddEdge(cb, i);
    }
    if (s[i] == 'C') {
      g.AddEdge(i, ca, xac);
      g.AddEdge(i, cb, xbc);
      g.AddEdge(ac, i);
      g.AddEdge(bc, i);
    }
  }
  rep(m) {
    ints(a, b, c);
    g.AddEdge(a - 1, b - 1, c);
    g.AddEdge(b - 1, a - 1, c);
  }
  wt(*Dijkstra(g, 0).dist[n - 1]);
}
