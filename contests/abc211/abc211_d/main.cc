#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m);
  VV<int> g(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  vector dist(n, big);
  vector dp(n, mint(0));
  queue<int> que;
  que.push(0);
  dist[0] = 0;
  dp[0] = 1;
  while (!que.empty()) {
    int I = que.front();
    que.pop();
    int D = dist[I] + 1;
    each(J, g[I]) {
      if (dist[J] < D) continue;
      if (dist[J] == D) {
        dp[J] += dp[I];
        continue;
      }
      if (dist[J] > D) {
        dp[J] = dp[I];
        dist[J] = D;
        que.push(J);
      }
    }
  }
  wt(dp[n - 1]);
}
