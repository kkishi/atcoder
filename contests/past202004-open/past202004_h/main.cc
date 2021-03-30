#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> a(n);
  cin >> a;
  vector dist(n, vector(m, big));
  queue<pair<int, int>> que;
  rep(i, n) rep(j, m) if (a[i][j] == 'S') {
    dist[i][j] = 0;
    que.emplace(i, j);
  }
  int ans = -1;
  while (!que.empty()) {
    auto [i, j] = que.front();
    que.pop();
    if (a[i][j] == 'G') ans = dist[i][j];
    rep(k, 4) {
      int di[] = {0, 1, 0, -1};
      int dj[] = {1, 0, -1, 0};
      int ni = i + di[k];
      int nj = j + dj[k];
      if (0 <= ni && ni < n && 0 <= nj && nj < m) {
        auto f = [](char c) { return c == 'S' ? 0 : c == 'G' ? 10 : c - '0'; };
        int x = f(a[i][j]);
        int y = f(a[ni][nj]);
        if ((x == y || x + 1 == y) && chmin(dist[ni][nj], dist[i][j] + 1)) {
          que.emplace(ni, nj);
        }
      }
    }
  }
  wt(ans);
}
