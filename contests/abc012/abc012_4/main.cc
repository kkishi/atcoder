#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, m);
  VV<int> dist(n, V<int>(n, big));
  rep(i, n) dist[i][i] = 0;
  rep(m) {
    ints(a, b, t);
    --a, --b;
    dist[a][b] = dist[b][a] = t;
  }
  WarshallFloyd(dist);
  int ans = big;
  rep(i, n) {
    int maxi = 0;
    rep(j, n) chmax(maxi, dist[i][j]);
    chmin(ans, maxi);
  }
  wt(ans);
}
