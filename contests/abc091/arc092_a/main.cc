#include <bits/stdc++.h>

#include "graph.h"

template <typename T>
T EdmondsKarp(const Graph<T>& g, int src, int dst) {
  int N = g.NumVertices();
  std::vector<std::vector<T>> flow(N, std::vector<T>(N));
  T total = 0;
  while (true) {
    std::queue<std::pair<int, T>> que;
    que.push({src, std::numeric_limits<T>::max()});
    std::vector<int> prev(N, -1);
    while (!que.empty()) {
      auto [u, f] = que.front();
      que.pop();
      if (u == dst) {
        total += f;
        while (u != src) {
          flow[prev[u]][u] += f;
          flow[u][prev[u]] -= f;
          u = prev[u];
        }
        break;
      }
      for (auto& e : g.Edges(u)) {
        if (prev[e.to] != -1) continue;
        T residue = e.weight - flow[u][e.to];
        if (residue == 0) continue;
        prev[e.to] = u;
        que.push({e.to, std::min(f, residue)});
      }
    }
    if (prev[dst] == -1) break;
  }
  return total;
}

#include "macros.h"

using namespace std;

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
  wt(EdmondsKarp(g, s, d));
}
