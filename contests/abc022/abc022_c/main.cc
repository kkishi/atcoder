#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, m);
  VV<int> dist(n, V<int>(n, big));
  V<pair<int, int>> e;
  rep(i, m) {
    ints(u, v, l);
    --u, --v;
    if (u > v) swap(u, v);
    if (u == 0) {
      e.emplace_back(v, l);
    } else {
      dist[u][v] = dist[v][u] = l;
    }
  }
  WarshallFloyd(dist);
  int ans = big;
  rep(i, sz(e) - 1) rep(j, i + 1, sz(e)) {
    chmin(ans, e[i].second + e[j].second + dist[e[i].first][e[j].first]);
  }
  wt(ans == big ? -1 : ans);
}
