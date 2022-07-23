#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

void Main() {
  ints(n, m, v);
  --v;
  WeightedGraph<int> g(n), rg(n);
  vector deg(2, vector(n, int(0)));
  rep(m) {
    ints(a, b, c);
    --a, --b;
    g[a].eb(b, c);
    rg[b].eb(a, c);
    rep(i, 2)++ deg[i][a];
  }
  vector dp(2, vector(n, big));
  using S = tuple<int, int, int>;
  low_priority_queue<S> que;
  rep(i, n) if (deg[0][i] == 0) {
    rep(j, 2) {
      que.emplace(0, i, j);
      dp[j][i] = 0;
    }
  }
  while (!que.empty()) {
    auto [cost, node, aoki] = que.top();
    que.pop();
    if (dp[aoki][node] != cost) continue;
    each(parent, weight, rg[node]) {
      bool deg0 = --deg[!aoki][parent] == 0;
      if (aoki) {
        if (chmin(dp[0][parent], cost + weight)) {
          que.emplace(cost + weight, parent, 0);
        }
      } else {
        if (deg0) {
          int ma = -big;
          each(child, weight, g[parent]) chmax(ma, dp[0][child] + weight);
          dp[1][parent] = ma;
          que.emplace(ma, parent, 1);
        }
      }
    }
  }
  if (dp[0][v] != big) {
    wt(dp[0][v]);
  } else {
    wt("INFINITY");
  }
}
