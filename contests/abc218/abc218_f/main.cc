#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "warshall_floyd.h"

template <typename T>
std::vector<std::optional<T>> Dijkstra(const WeightedGraph<T>& graph, int start,
                                       int I) {
  const int n = graph.size();

  std::vector<std::optional<T>> dist(n);

  using element = std::pair<T, int>;
  // std::priority_queue<element, std::vector<element>, std::greater<>> que;
  std::queue<element> que;

  auto push = [&dist, &que](int u, T c) {
    if (dist[u] && *dist[u] <= c) return;
    dist[u] = c;
    que.push({c, u});
  };

  push(start, 0);

  while (!que.empty()) {
    auto [c, u] = que.front();
    que.pop();
    if (c > dist[u]) continue;
    for (auto [to, w] : graph[u]) {
      if (w != I) {
        push(to, c + 1);
      }
    }
  }

  return dist;
}

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  vector dist(n, vector(n, big));
  rep(i, n) dist[i][i] = 0;
  V<pair<int, int>> es;
  rep(i, m) {
    ints(s, t);
    --s, --t;
    g[s].eb(t, i);
    dist[s][t] = 1;
    es.eb(s, t);
  }
  WarshallFloyd(dist);
  rep(i, m) {
    auto [s, t] = es[i];
    if (s != 0 && t != n - 1 &&
        dist[0][n - 1] < dist[0][s] + 1 + dist[t][n - 1]) {
      int ans = dist[0][n - 1];
      if (ans == big) ans = -1;
      wt(ans);
    } else {
      auto d = Dijkstra(g, 0, i);
      if (d[n - 1]) {
        wt(*d[n - 1]);
      } else {
        wt(-1);
      }
    }
  }
}
