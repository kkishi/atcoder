#include <bits/stdc++.h>

#include "dijkstra.h"
#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  V<optional<int>> df = Dijkstra(g, 0), ds = Dijkstra(g, n - 1);
  int f = 0;
  rep(i, n) f += (*df[i] <= *ds[i]) ? 1 : -1;
  wt(f > 0 ? "Fennec" : "Snuke");
}
