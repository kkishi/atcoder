#include <bits/stdc++.h>

#include "graph.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  Graph<ll> g(n);
  rep(i, n - 1) {
    rd(ll, u, v, w);
    --u, --v;
    g.AddEdge(u, v, w);
    g.AddEdge(v, u, w);
  }
  vector<ll> color(n, -1);
  Fix([&](auto dfs, ll node, ll parent, ll dist) -> void {
    color[node] = dist % 2;
    for (const auto& e : g.Edges(node)) {
      if (e.to == parent) continue;
      if (color[e.to] != -1) continue;
      dfs(e.to, node, dist + e.weight);
    }
  })(0, -1, 0);
  rep(i, n) wt(color[i]);
}
