#include <bits/stdc++.h>

#include "bellman_ford.h"
#include "dijkstra.h"
#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, m);
  V<int> a(m), b(m), c(m);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i], --b[i];
  }

  Graph<int> rg(n);
  rep(i, m) rg.AddEdge(b[i], a[i], 0);
  V<optional<int>> rd = Dijkstra(rg, n - 1);

  Graph<int> g(n);
  rep(i, m) if (rd[b[i]]) g.AddEdge(a[i], b[i], -c[i]);

  if (auto [e, ok] = BellmanFord(g, 0); ok) {
    wt(-e[n - 1]);
  } else {
    wt("inf");
  }
}