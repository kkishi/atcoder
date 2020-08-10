#include <bits/stdc++.h>

#include "graph.h"
#include "macros.h"

using namespace std;

struct Weight {
  int color, length;
};

int main() {
  rd(int, n, q);
  Graph<Weight> g(n);
  rep(i, n - 1) {
    rd(int, a, b, c, d);
    --a, --b;
    g.AddEdge(a, b, {c, d});
    g.AddEdge(b, a, {c, d});
  }
  vector<int> ins(n), outs(n);
  vector<int> depths;
  function<void(int, int, int)> dfs = [&](int node, int parent, int depth) {
    int index = depths.size();
    ins[node] = index;
    depths.push_back(depth);
    for (const auto& e : g.Edges(node)) {
      if (e.to == parent) continue;
      dfs(e.to, node, depth + 1);
    }
  };
  dfs(0, -1, 0);
}
