#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  g.Read(m);
  {
    set<int> seen;
    V<pair<int, int>> ans;
    Fix([&](auto rec, int node) {
      if (!seen.insert(node).second) return;
      each(child, g[node]) if (!seen.count(child)) {
        ans.eb(node, child);
        rec(child);
      }
    })(0);
    each(i, j, ans) wt(i + 1, j + 1);
  }
  {
    V<int> d(n, big);
    d[0] = 0;
    queue<int> que;
    que.push(0);
    V<pair<int, int>> ans;
    while (!que.empty()) {
      int node = que.front();
      que.pop();
      each(child, g[node]) if (chmin(d[child], d[node] + 1)) {
        que.push(child);
        ans.eb(node, child);
      }
    }
    each(i, j, ans) wt(i + 1, j + 1);
  }
}
