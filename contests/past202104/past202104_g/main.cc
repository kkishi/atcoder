#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, q);
  VV<tuple<int, int>> to(n);
  rep(m) {
    ints(a, b, c);
    --a, --b;
    to[a].eb(b, c);
    to[b].eb(a, c);
  }
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
