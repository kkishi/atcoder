#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> a(n);
  cin >> a;
  vector dist(n, vector(m, vector(11, big)));
  queue<tuple<int, int, int>> que;
  rep(i, n) rep(j, m) if (a[i][j] == 'S') {
    dist[i][j][0] = 0;
    que.emplace(i, j, 0);
  }
  while (!que.empty()) {
    auto [i, j, k] = que.front();
    que.pop();
    if (k == 10 && a[i][j] == 'G') {
      wt(dist[i][j][k]);
      return;
    }
    each(ni, nj, adjacent(i, j)) {
      if (!inside(ni, nj, n, m)) continue;
      char c = a[ni][nj];
      int x = (c == 'S' ? 0 : c == 'G' ? 10 : (c - '0'));
      int nk = x == k + 1 ? k + 1 : k;
      if (chmin(dist[ni][nj][nk], dist[i][j][k] + 1)) que.emplace(ni, nj, nk);
    }
  }
  wt(-1);
}
