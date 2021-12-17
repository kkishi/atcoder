#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  vector dist(h, vector(w, big));
  queue<pair<int, int>> que;
  dist[0][0] = 0;
  que.emplace(0, 0);
  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();
    each(nr, nc, adjacent(r, c)) if (inside(nr, nc, h, w)) {
      if (s[r][c] != s[nr][nc] && chmin(dist[nr][nc], dist[r][c] + 1)) {
        que.emplace(nr, nc);
      }
    }
  }
  int ans = dist[h - 1][w - 1];
  if (ans == big) ans = -1;
  wt(ans);
}
