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

    using P = pair<int, int>;
    queue<P> que;
    auto push = [&](P p, int c) {
      auto [t, a] = p;
      if (chmin(dist[t][a], c)) {
        que.emplace(p);
      }
    };
    push({0, n - 1}, 0);
    while (!que.empty()) {
      auto [t, a] = que.front();
      que.pop();
      each(nt, g[t]) each(na, g[a]) if (c[nt] != c[na]) {
        push({nt, na}, dist[t][a] + 1);
      }
    }
    int ans = dist[n - 1][0];
    if (ans == big) ans = -1;
    wt(ans);
  }
}
