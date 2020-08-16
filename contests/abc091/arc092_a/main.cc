#include <bits/stdc++.h>

#include "graph.h"
#include "macros.h"

using namespace std;

template <typename T>
T FordFulkerson(const Graph<T>& g, int s, int d) {
  VV<T> flow(g.NumVertices(), V<T>(g.NumVertices()));
  T total = 0;
  while (true) {
    queue<pair<int, T>> que;
    que.push({s, numeric_limits<T>::max()});
    V<int> prev(g.NumVertices(), -1);
    while (!que.empty()) {
      auto [h, x] = que.front();
      que.pop();
      if (h == d) {
        total += x;
        while (h != s) {
          flow[prev[h]][h] += x;
          flow[h][prev[h]] -= x;
          h = prev[h];
        }
        break;
      }
      for (auto& e : g.Edges(h)) {
        if (prev[e.to] != -1) continue;
        T residue = e.weight - flow[e.from][e.to];
        if (residue == 0) continue;
        prev[e.to] = e.from;
        que.push({e.to, min(x, residue)});
      }
    }
    if (prev[d] == -1) break;
  }
  return total;
}

struct XY {
  int x, y;
};

int main() {
  rd(int, n);
  Graph<int> g(n * 2 + 2);
  V<XY> r(n), b(n);
  rep(i, n) cin >> r[i].x >> r[i].y;
  rep(i, n) cin >> b[i].x >> b[i].y;
  const int r0 = 0, b0 = r0 + n, s = b0 + n, d = s + 1;
  auto add = [&](int i, int j) {
    g.AddEdge(i, j, 1);
    g.AddEdge(j, i, 0);
  };
  rep(i, n) add(s, r0 + i);
  rep(i, n) add(b0 + i, d);
  rep(i, n) rep(j, n) if (r[i].x < b[j].x && r[i].y < b[j].y)
      add(r0 + i, b0 + j);
  wt(FordFulkerson(g, s, d));
}
