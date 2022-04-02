#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  ints(ax, ay, bx, by);
  --ax, --ay, --bx, --by;
  V<string> s(n);
  cin >> s;
  int dx[] = {1, 1, -1, -1};
  int dy[] = {1, -1, 1, -1};
  vector dist(n, vector(n, vector(4, big)));
  using P = tuple<int, int, int>;
  deque<P> que;
  rep(i, 4) {
    dist[ax][ay][i] = 1;
    que.eb(ax, ay, i);
  }
  while (!que.empty()) {
    auto [x, y, dir] = que.front();
    que.pop_front();
    rep(ndir, 4) {
      int nd = dist[x][y][dir];
      bool front = true;
      if (ndir != dir) {
        ++nd;
        front = false;
      }
      int nx = x + dx[ndir];
      int ny = y + dy[ndir];
      if (inside(nx, ny, n, n) &&
          (s[nx][ny] == '.') & chmin(dist[nx][ny][ndir], nd)) {
        if (front) {
          que.emplace_front(nx, ny, ndir);
        } else {
          que.emplace_back(nx, ny, ndir);
        }
      }
    }
  }
  int ans = big;
  rep(i, 4) chmin(ans, dist[bx][by][i]);
  if (ans == big) ans = -1;
  wt(ans);
}
