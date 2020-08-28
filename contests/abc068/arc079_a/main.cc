#include <bits/stdc++.h>

#include "dijkstra.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  Graph<int> g(n + 1);
  rep(m) {
    ints(a, b);
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }
  optional<int> d = Dijkstra(g, 1)[n];
  wt((d && d == 2) ? "POSSIBLE" : "IMPOSSIBLE");
}
