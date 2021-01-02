#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, c, k);
  V<string> s(r);
  cin >> s;
  VV<int> dist(r, V<int>(c, big));
  queue<pair<int, int>> que;
  rep(i, r) rep(j, c) if (s[i][j] == 'x') {
    dist[i][j] = 0;
    que.push({i, j});
  }
  while (!que.empty()) {
    auto [i, j] = que.front();
    que.pop();
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    rep(d, 4) {
      int ni = i + dr[d];
      int nj = j + dc[d];
      if (0 <= ni && ni < r && 0 <= nj && nj < c &&
          chmin(dist[ni][nj], dist[i][j] + 1)) {
        que.push({ni, nj});
      }
    }
  }
  int ans = 0;
  rep(i, k - 1, r - k + 1) rep(j, k - 1, c - k + 1) if (dist[i][j] >= k)++ ans;
  wt(ans);
}
