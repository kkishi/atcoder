#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

const int INF = 1LL << 60;

void Main() {
  ints(n, m, l);

  VV<int> dist(n, V<int>(n, INF));
  rep(i, m) {
    ints(a, b, c);
    if (c <= l) {
      --a, --b;
      dist[a][b] = dist[b][a] = c;
    }
  }
  WarshallFloyd(dist);

  VV<int> dist2(n, V<int>(n, INF));
  rep(i, n) rep(j, n) if (dist[i][j] <= l) dist2[i][j] = 1;
  WarshallFloyd(dist2);

  ints(q);
  rep(i, q) {
    ints(s, t);
    --s, --t;
    int d = dist2[s][t];
    if (d == INF) {
      wt(-1);
    } else {
      wt(d - 1);
    }
  }
}
