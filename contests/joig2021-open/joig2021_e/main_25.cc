#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "graph.h"

void Main1(int n, int m, int l) {
  WeightedGraph<tuple<int, bool>> g(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g.AddEdge(a, b, {c, false});
    g.AddEdge(b, a, {c, true});
  }
  wt(Fix([&](auto rec, int node, int parent, int dist, int changed) -> int {
    if (node == n - 1) {
      if (dist <= l) {
        return changed;
      } else {
        return -1;
      }
    }
    each(e, g.Edges(node)) {
      if (e.to == parent) continue;
      auto [cost, flipped] = e.weight;
      int res = rec(e.to, node, dist + cost, changed + flipped);
      if (res >= 0) return res;
    }
    return -1;
  })(0, -1, 0, 0));
}

void Main2(int n, int m, int l) {
  WeightedGraph<int> g(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c);
  }
  if (*Dijkstra(g, 0).dist[n - 1] <= l) {
    wt(0);
  } else {
    wt(-1);
  }
}

void Main3(int n, int m, int l) {
  WeightedGraph<tuple<int, int, bool>> g(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    g.AddEdge(a, b, {c, i, false});
    g.AddEdge(b, a, {c, i, true});
  }
  vector dist(1 << m, vector(n, big));
  low_priority_queue<tuple<int, int, int>> que;
  auto push = [&](int dis, int mask, int node) {
    if (chmin(dist[mask][node], dis)) que.emplace(dis, mask, node);
  };
  push(0, 0, 0);
  while (!que.empty()) {
    auto [dis, mask, node] = que.top();
    que.pop();
    if (dis > dist[mask][node]) continue;
    each(e, g.Edges(node)) {
      auto [cos, idx, flipped] = e.weight;
      int nmask = mask;
      if (flipped) nmask |= 1 << idx;
      push(dis + cos, nmask, e.to);
    }
  }
  int ans = big;
  rep(mask, 1 << m) if (dist[mask][n - 1] <= l) chmin(ans, popcount(mask));
  if (ans == big) ans = -1;
  wt(ans);
}

void Main() {
  ints(n, m, l);
  if (n <= 15 && m <= 15) {
    Main3(n, m, l);
  } else if (m == n - 1) {
    Main1(n, m, l);
  } else if (even(m)) {
    Main2(n, m, l);
  }
}
