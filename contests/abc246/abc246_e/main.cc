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

  // 01BFS
  vector dist(n, vector(n, vector(4, big)));
  deque<tuple<int, int, int, int>> que;
  rep(i, 4) {
    dist[ax][ay][i] = 1;
    que.eb(ax, ay, i, 1);
  }
  while (!que.empty()) {
    auto [x, y, dir, dis] = que.front();
    que.pop_front();
    rep(ndir, 4) {
      int w = ndir != dir;
      int nx = x + dx[ndir];
      int ny = y + dy[ndir];
      if (inside(nx, ny, n, n) && (s[nx][ny] == '.') &&
          chmin(dist[nx][ny][ndir], dis + w)) {
        if (w == 0) {
          que.emplace_front(nx, ny, ndir, dis + w);
        } else {
          que.emplace_back(nx, ny, ndir, dis + w);
        }
      }
    }
  }
  int ans = min(dist[bx][by]);
  if (ans == big) ans = -1;
  wt(ans);
}
