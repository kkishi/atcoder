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
    vector dist(N, vector(M, big));
    que.push({sr, sc});
    dist[sr][sc] = 0;
    while (!que.empty()) {
      auto [r, c] = que.front();
      que.pop();
      each(nr, nc, adjacent(r, c)) {
        if (inside(nr, nc, N, M)) {
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
