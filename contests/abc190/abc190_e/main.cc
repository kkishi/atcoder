#include <bits/stdc++.h>

#include "atcoder.h"
#include "dijkstra.h"

void Main() {
  ints(n, m);
  Graph<int> g(n);
  rep(i, m) {
    ints(a, b);
    --a, --b;
    g.AddEdge(a, b, 1);
    g.AddEdge(b, a, 1);
  }

  ints(k);
  V<int> c(k);
  cin >> c;

  vector dist(k, vector(k, big));
  rep(i, k) {
    V<optional<int>> d = Dijkstra(g, c[i] - 1);
    rep(j, k) if (d[c[j] - 1]) dist[i][j] = *d[c[j] - 1];
  }

  vector dp(1 << k, vector(k, big));
  rep(i, k) dp[1 << i][i] = 1;
  rep(s, 1, 1 << k) rep(i, k) if (!hasbit(s, i)) rep(j, k) if (hasbit(s, j)) {
    chmin(dp[s | (1 << i)][i], dp[s][j] + dist[j][i]);
  }
  int ans = big;
  rep(i, k) chmin(ans, dp[(1 << k) - 1][i]);
  if (ans == big) ans = -1;
  wt(ans);
}
