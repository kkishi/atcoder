#include <bits/stdc++.h>

#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
#define int ll

  ints(n, m);
  Graph<int> g(n);
  rep(i, m) {
    ints(l, r, d);
    --l, --r;
    g.AddEdge(l, r, d);
    g.AddEdge(r, l, -d);
  }

  const int inf = numeric_limits<int>::max();
  V<int> seen(n, inf);
  rep(i, n) if (seen[i] == inf) {
    seen[i] = 0;
    queue<pair<int, int>> que;
    que.push({i, 0});
    while (!que.empty()) {
      auto [u, p] = que.front();
      que.pop();
      for (const auto& e : g.Edges(u)) {
        int v = e.to;
        int w = p + e.weight;
        if (seen[v] != inf) {
          if (seen[v] != w) {
            wt("No");
            return false;
          }
          continue;
        }
        seen[v] = w;
        que.push({v, w});
      }
    }
  }
  wt("Yes");
}
