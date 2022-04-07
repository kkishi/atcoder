#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, m);
  vector dist(n, vector(n, big));
  rep(i, n) dist[i][i] = 0;
  rep(m) {
    ints(u, v, c);
    dist[u][v] = c;
  }
  WarshallFloyd(dist);
  int ans = 0;
  rep(i, n) rep(j, n) ans += dist[i][j];
  wt(ans);
}
