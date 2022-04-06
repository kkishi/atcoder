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

  // Dijkstra with pruning
  vector dist(n, vector(n, vector(4, big)));
  struct S {
    int x, y, dir, dis;
    bool operator<(const S& s) const { return dis > s.dis; }
  };
  priority_queue<S> que;
  rep(i, 4) {
    dist[ax][ay][i] = 1;
    que.push({ax, ay, i, 1});
  }
  while (!que.empty()) {
    auto [x, y, dir, dis] = que.top();
    que.pop();
    rep(ndir, 4) {
      int nx = x + dx[ndir];
      int ny = y + dy[ndir];
      int ndis = dis + (ndir != dir);
      if (inside(nx, ny, n, n) && (s[nx][ny] == '.') &&
          chmin(dist[nx][ny][ndir], ndis)) {
        que.push({nx, ny, ndir, ndis});
      }
    }
  }
  int ans = min(dist[bx][by]);
  if (ans == big) ans = -1;
  wt(ans);
}
