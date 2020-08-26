#include <bits/stdc++.h>

#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b, c);
    --a, --b;
    g.AddEdge(a, b, c);
    g.AddEdge(b, a, c);
  }
  ints(q, k);
  --k;
  V<int> dist(n, -1);
  dist[k] = 0;
  Fix([&](auto dfs, int n, int p, int d) -> void {
    dist[n] = d;
    for (auto& e : g.Edges(n)) {
      if (e.to == p) continue;
      dfs(e.to, n, d + e.weight);
    }
  })(k, -1, 0);
  rep(q) {
    ints(x, y);
    --x, --y;
    wt(dist[x] + dist[y]);
  }
}
