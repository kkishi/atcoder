#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "strongly_connected_component.h"

void Main() {
  ints(n, m);
  Graph<int> graph(n);
  rep(i, m) {
    ints(a, b);
    graph.AddEdge(a - 1, b - 1, 0);
  }
  vector<vector<int>> sccs = StronglyConnectedComponents(graph);
  for (const vector<int>& scc : sccs) {
    if (scc.size() == 1) continue;
    set<int> scc_nodes(all(scc));
    int node = scc[0];
    map<int, int> next;
    map<int, int> prev;
    for (int n : scc_nodes) dbg(n);
    while (true) {
      for (auto& e : graph.Edges(node)) {
        int child = e.to;
        if (scc_nodes.count(child) == 0) continue;
        next[node] = child;
        prev[child] = node;
        if (next.count(child) != 0) goto out;
        node = child;
        break;
      }
    }
  out:
    node = scc[0];
    if (prev.count(node) == 0) {
      while (true) {
        int child = next[node];
        next.erase(node);
        if (prev[child] != node) break;
        prev.erase(child);
        node = child;
      }
    }
    rep(u, n) for (auto& e : graph.Edges(u)) {
      int v = e.to;
      if (next.count(u) > 0 && next.count(v) > 0) {
        int c = next[u];
        while (c != v) {
          int nc = next[c];
          next.erase(c);
          prev.erase(c);
          c = nc;
        }
        next[u] = v;
        prev[v] = u;
      }
    }
    vector<int> v;
    int u = next.begin()->first;
    do {
      v.pb(u);
      u = next[u];
    } while (u != next.begin()->first);
    wt(v.size());
    for (int u : v) wt(u + 1);
    return;
  }
  wt(-1);
}
