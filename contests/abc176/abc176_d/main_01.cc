#include <bits/stdc++.h>

#include "atcoder.h"

template <typename T>
bool between(const T& v, const T& lo, const T& hi) {
  return lo <= v && v <= hi;
}

void Main() {
  ints(h, w);
  ints(ch, cw);
  --ch, --cw;
  ints(dh, dw);
  --dh, --dw;
  V<string> s(h);
  cin >> s;

  deque<pair<int, int>> que;
  const int inf = numeric_limits<int>::max();
  VV<int> dist(h, V<int>(w, inf));

  que.push_front({ch, cw});
  dist[ch][cw] = 0;

  while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop_front();
    auto ok = [&](int r, int c) {
      return between(r, 0L, h - 1) && between(c, 0L, w - 1) && s[r][c] == '.';
    };
    rep(i, 4) {
      int dr[] = {0, 1, 0, -1};
      int dc[] = {1, 0, -1, 0};
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (ok(nr, nc) && chmin(dist[nr][nc], dist[r][c])) {
        que.push_front({nr, nc});
      }
    }
    rep(dr, -2, 3) rep(dc, -2, 3) {
      int nr = r + dr;
      int nc = c + dc;
      if (ok(nr, nc) && chmin(dist[nr][nc], dist[r][c] + 1)) {
        que.push_back({nr, nc});
      }
    }
  }
  int ans = dist[dh][dw];
  wt(ans == inf ? -1 : ans);
}
