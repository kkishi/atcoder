#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n);
  VV<int> a(n, V<int>(n));
  cin >> a;
  VV<int> b = a;
  WarshallFloyd(b);
  if (a != b) {
    wt(-1);
    return;
  }
  V<tuple<int, int, int>> e;
  rep(i, n - 1) rep(j, i + 1, n) e.push_back({a[i][j], i, j});
  sort(all(e));
  int ans = 0;
  VV<int> dist(n, V<int>(n, 10000000000LL));
  for (auto [w, u, v] : e) {
    if (dist[u][v] == w) continue;
    dist[u][v] = dist[v][u] = w;
    rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][u] + dist[u][j]);
    rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][v] + dist[v][j]);
    ans += w;
  }
  wt(ans);
}
