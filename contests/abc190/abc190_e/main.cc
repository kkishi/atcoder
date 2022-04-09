#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"
#include "travelling_salesperson_problem.h"

void Main() {
  ints(n, m);
  WeightedGraph<int> g(n);
  rep(i, m) {
    ints(a, b);
    --a, --b;
    g[a].eb(b, 1);
    g[b].eb(a, 1);
  }

  ints(k);
  V<int> c(k);
  cin >> c;
  each(e, c)-- e;

  vector dp(1 << k, vector(k, big));
  rep(i, k) dp[1 << i][i] = 1;
  vector dist(k, vector(k, big));
  rep(i, k) {
    V<optional<int>> d = Dijkstra(g, c[i]).dist;
    rep(j, k) if (d[c[j]]) dist[i][j] = *d[c[j]];
  }
  TravellingSalespersonProblem(dp, dist);

  int ans = min(dp.back());
  if (ans == big) ans = -1;
  wt(ans);
}
