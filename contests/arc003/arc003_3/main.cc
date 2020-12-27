#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(N, M);
  V<string> grid(N);
  cin >> grid;
  int sr, sc;
  rep(i, N) rep(j, M) if (grid[i][j] == 's') sr = i, sc = j;
  auto bfs = [&](double x) {
    queue<pair<int, int>> que;
    int inf = numeric_limits<int>::max() / 10;
    vector dist(N, vector(M, inf));
    que.push({sr, sc});
    dist[sr][sc] = 0;
    while (!que.empty()) {
      auto [r, c] = que.front();
      que.pop();
      rep(i, 4) {
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 <= nr && nr < N && 0 <= nc && nc < M) {
          char g = grid[nr][nc];
          if (g == '#') continue;
          if (g == 's') continue;
          if (g == 'g') return true;
          int d = dist[r][c] + 1;
          if ((g - '0') * pow(0.99, d) < x) continue;
          if (chmin(dist[nr][nc], d)) que.push({nr, nc});
        }
      }
    }
    return false;
  };
  if (!bfs(0)) {
    wt(-1);
    return;
  }
  // This fails with a TLE unless the iteration is reduced down from 200 to 50.
  wt(BinarySearch<double>(0, 10, bfs));
}
