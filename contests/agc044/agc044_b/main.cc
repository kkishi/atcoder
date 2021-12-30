#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n * n);
  cin >> p;

  vector dist(n, vector(n, int(0)));
  rep(r, n) rep(c, n) dist[r][c] = min({r, n - 1 - r, c, n - 1 - c});

  vector gone(n, vector(n, false));

  int ans = 0;
  each(pi, p) {
    int i = (pi - 1) / n;
    int j = (pi - 1) % n;
    ans += dist[i][j];
    gone[i][j] = true;
    queue<pair<int, int>> que;
    que.emplace(i, j);
    while (!que.empty()) {
      auto [i, j] = que.front();
      que.pop();
      each(ni, nj, adjacent(i, j)) if (inside(ni, nj, n, n)) {
        int d = gone[i][j] ? 0 : 1;
        if (chmin(dist[ni][nj], dist[i][j] + d)) {
          que.emplace(ni, nj);
        }
      }
    }
  }
  wt(ans);
}
