#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, X, Y);
  X += 300;
  Y += 300;
  vector o(601, vector(601, false));
  rep(N) {
    ints(x, y);
    o[x + 300][y + 300] = true;
  }
  vector d(601, vector(601, big));
  d[300][300] = 0;
  queue<pair<int, int>> q;
  q.emplace(300, 300);
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int dx[] = {1, 0, -1, 1, -1, 0};
    int dy[] = {1, 1, 1, 0, 0, -1};
    rep(i, 6) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inside(nx, ny, 601, 601) && !o[nx][ny] &&
          chmin(d[nx][ny], d[x][y] + 1)) {
        q.emplace(nx, ny);
      }
    }
  }
  int ans = d[X][Y];
  if (ans == big) ans = -1;
  wt(ans);
}
