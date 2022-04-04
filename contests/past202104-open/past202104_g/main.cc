#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, q);
  WeightedGraph<int> to(n);
  to.Read(m);
  V<int> x(q);
  cin >> x;

  low_priority_queue<tuple<int, int>> que;
  each(x, c, to[0]) que.emplace(c, x);

  V<bool> visited(n);
  visited[0] = true;
  int ans = 1;

  rep(i, q) {
    set<tuple<int, int>> s;
    while (!que.empty()) {
      auto [c, b] = que.top();
      if (c > x[i]) break;
      que.pop();
      if (!visited[b]) s.insert({c, b});
    }
    each(c, b, s) {
      if (visited[b]) continue;
      visited[b] = true;
      ++ans;
      each(nb, nc, to[b]) if (!visited[nb]) que.emplace(nc, nb);
    }
    wt(ans);
  }
}
