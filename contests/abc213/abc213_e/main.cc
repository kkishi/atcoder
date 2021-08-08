#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  low_priority_queue<tuple<int, int, int>> que;
  que.emplace(0, 0, 0);
  vector dist(h, vector(w, big));
  dist[0][0] = 0;
  while (!que.empty()) {
    auto [d, r, c] = que.top();
    que.pop();
    dbg(d, r, c);
    if (d > dist[r][c]) continue;
    rep(dr, -2, 3) rep(dc, -2, 3) {
      int md = abs(dr) + abs(dc);
      if (md == 4) continue;
      int nr = r + dr;
      int nc = c + dc;
      if (!inside(nr, nc, h, w)) continue;
      int nd = d;
      if (md > 1 || s[nr][nc] == '#') ++nd;
      if (chmin(dist[nr][nc], nd)) {
        que.emplace(nd, nr, nc);
      }
    }
  }
  // each(e, dist) dbg(e);
  wt(dist[h - 1][w - 1]);
}
