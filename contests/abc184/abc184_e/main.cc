#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  int sr, sc;
  map<char, V<pair<int, int>>> t;
  rep(i, h) rep(j, w) {
    if (a[i][j] == 'S') {
      sr = i, sc = j;
    }
  }
  vector dist(h, vector(w, big));
  dist[sr][sc] = 0;
  queue<pair<int, int>> que;
  que.push({sr, sc});
  set<char> used;
  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    if (a[r][c] == 'G') {
      wt(dist[r][c]);
      return;
    }
    rep(i, 4) {
      int dr[] = {1, 0, -1, 0};
      int dc[] = {0, 1, 0, -1};
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 <= nr && nr < h && 0 <= nc && nc < w) {
        if (a[nr][nc] != '#') {
          if (chmin(dist[nr][nc], dist[r][c] + 1)) {
            que.push({nr, nc});
          }
        }
      }
    }
    if (char ai = a[r][c]; 'a' <= ai && ai <= 'z') {
      if (used.insert(ai).second) {
        rep(i, h) rep(j, w) if (a[i][j] == ai) {
          if (chmin(dist[i][j], dist[r][c] + 1)) {
            que.push({i, j});
          }
        }
      }
    }
  }
  wt(-1);
}
