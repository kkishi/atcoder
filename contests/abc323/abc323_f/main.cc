#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(xa, ya, xb, yb, xc, yc);
  // normalize
  xa -= xb;
  xc -= xb;
  ya -= yb;
  yc -= yb;
  while (xc < 0 || yc < 0) {
    swap(xa, ya);
    xa = -xa;
    swap(xc, yc);
    xc = -xc;
  }
  int ans = big;
  rep(2) {
    swap(xa, ya);
    swap(xc, yc);
    int mi = big;
    int sx, sy, sd;
    rep(x, -1, 2) rep(y, -1, 2) if (x || y) {
      int d = abs(xa - x) + abs(ya - y);
      if (chmin(mi, d)) {
        sx = x;
        sy = y;
        sd = d;
      }
    }
    using P = pair<int, int>;
    map<P, int> dist;
    dist[{sx, sy}] = 0;
    queue<P> que;
    que.push({sx, sy});
    while (!que.empty()) {
      auto [x, y] = que.front();
      que.pop();
      if (x == 0 && y == -1) {
        int cost = sd + dist[{x, y}] + yc;
        if (xc > 0) cost += 2 + xc;
        chmin(ans, cost);
        break;
      }
      int dx[] = {0, 1, 0, -1};
      int dy[] = {1, 0, -1, 0};
      rep(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx != 0 || ny != 0) {
          if (!dist.count({nx, ny})) {
            dist[{nx, ny}] = dist[{x, y}] + 1;
            que.push({nx, ny});
          }
        }
      }
    }
  }
  wt(ans);
}
