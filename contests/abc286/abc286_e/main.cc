#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<string> s(n);
  cin >> s;
  vector dist(n, vector(n, big));
  vector cost(n, vector(n, int(0)));
  rep(i, n) rep(j, n) if (s[i][j] == 'Y') dist[i][j] = 1;
  rep(k, n) rep(i, n) rep(j, n) {
    int nd = dist[i][k] + dist[k][j];
    int nc = cost[i][k] + a[k] + cost[k][j];
    if (dist[i][j] > nd || (dist[i][j] == nd && cost[i][j] < nc)) {
      dist[i][j] = nd;
      cost[i][j] = nc;
    }
  }
  ints(q);
  rep(q) {
    ints(u, v);
    --u, --v;
    if (dist[u][v] == big) {
      wt("Impossible");
    } else {
      wt(dist[u][v], cost[u][v] + a[u] + a[v]);
    }
  }
}
