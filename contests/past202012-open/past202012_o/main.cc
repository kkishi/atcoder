#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> degree(n);
  VV<int> graph(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    ++degree[a];
    ++degree[b];
    graph[a].pb(b);
    graph[b].pb(a);
  }
  auto small = [&](int x) { return degree[x] * degree[x] < n; };
  VV<int> graph_big(n);
  rep(i, n) each(c, graph[i]) if (!small(c)) graph_big[i].pb(c);
  V<int> pub(n), sub(n);
  ints(q);
  V<int> prev_ans(n);
  rep(q) {
    ints(t, x);
    --x;
    if (t == 1) {
      if (small(x)) {
        each(c, graph[x])++ sub[c];
      } else {
        ++pub[x];
        each(c, graph_big[x])++ sub[c];
      }
    } else {
      int ans = sub[x];
      if (small(x)) {
        each(c, graph[x]) ans += pub[c];
      }
      wt(ans - prev_ans[x]);
      prev_ans[x] = ans;
    }
  }
}
