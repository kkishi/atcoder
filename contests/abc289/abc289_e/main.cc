#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n, m);
    Graph g(n);
    V<int> c(n);
    cin >> c;
    g.Read(m);
    vector dist(n, vector(n, big));

    using Cost = int;
    using State = pair<int, int>;
    using P = std::pair<Cost, State>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    auto push = [&](State state, Cost cost) {
      if (chmin(dist[state.first][state.second], cost)) {
        que.emplace(cost, state);
      }
    };
    push({0, n - 1}, 0);
    while (!que.empty()) {
      auto [cost, state] = que.top();
      que.pop();
      auto [t, a] = state;
      if (dist[t][a] < cost) continue;
      each(nt, g[t]) each(na, g[a]) if (c[nt] != c[na]) {
        push({nt, na}, cost + 1);
      }
    }
    int ans = dist[n - 1][0];
    if (ans == big) ans = -1;
    wt(ans);
  }
}
