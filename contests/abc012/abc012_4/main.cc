#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, m);
  const int inf = numeric_limits<int>::max() / 10;
  VV<int> dist(n, V<int>(n, inf));
  rep(i, n) dist[i][i] = 0;
  rep(m) {
    ints(a, b, t);
    --a, --b;
    dist[a][b] = dist[b][a] = t;
  }
  WarshallFloyd(dist);
  int ans = inf;
  rep(i, n) {
    int maxi = 0;
    rep(j, n) chmax(maxi, dist[i][j]);
    chmin(ans, maxi);
  }
  wt(ans);
}
