#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, k);
  V<string> a(h);
  cin >> a;
  int sr, sc;
  rep(i, h) rep(j, w) if (a[i][j] == 'S') sr = i, sc = j;

  vector dist(h, vector(w, big));
  queue<pair<int, int>> que;
  que.push({sr, sc});
  dist[sr][sc] = 0;
  rep(iter, 2) {
    while (!que.empty()) {
      auto [r, c] = que.front();
      que.pop();
      if (iter == 0 && dist[r][c] == k) continue;
      if (r == 0 || r == h - 1 || c == 0 || c == w - 1) {
        if (iter == 0) {
          wt(1);
        } else {
          wt(1 + (dist[r][c] + k - 1) / k);
        }
        return;
      }
      int dr[] = {0, 1, 0, -1};
      int dc[] = {1, 0, -1, 0};
      rep(d, 4) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || h <= nr || nc < 0 || w <= nc) continue;
        if (iter == 0 && a[nr][nc] == '#') continue;
        if (chmin(dist[nr][nc], dist[r][c] + 1)) {
          que.push({nr, nc});
        }
      }
    }
    if (iter == 0) rep(i, h) rep(j, w) if (dist[i][j] < big) {
        dist[i][j] = 0;
        que.push({i, j});
      }
  }
  assert(false);
}
