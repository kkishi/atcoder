#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  deque<tuple<int, int, int>> que;
  que.eb(0, 0, 0);
  vector dist(h, vector(w, big));
  dist[0][0] = 0;
  while (!que.empty()) {
    auto [d, r, c] = que.front();
    que.pop_front();
    rep(dr, -2, 3) rep(dc, -2, 3) {
      int md = abs(dr) + abs(dc);
      if (md == 4) continue;
      int nr = r + dr;
      int nc = c + dc;
      if (!inside(nr, nc, h, w)) continue;
      int dd = 0;
      if (md > 1 || s[nr][nc] == '#') dd = 1;
      int nd = d + dd;
      if (chmin(dist[nr][nc], nd)) {
        if (dd == 1) {
          que.eb(nd, nr, nc);
        } else {
          que.emplace_front(nd, nr, nc);
        }
      }
    }
  }
  wt(dist[h - 1][w - 1]);
}
