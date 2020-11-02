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

  int inf = numeric_limits<int>::max();
  VV<int> dist(h, V<int>(w, inf));
  low_priority_queue<tuple<int, int, int>> que;

  auto push = [&](int r, int c, int d) {
    if (!between(r, 0L, h - 1) || !between(c, 0L, w - 1) || s[r][c] == '#')
      return;
    if (!chmin(dist[r][c], d)) return;
    que.push({d, r, c});
  };
  push(ch, cw, 0);

  while (!que.empty()) {
    auto [d, r, c] = que.top();
    que.pop();
    rep(i, 4) {
      int dr[] = {0, 1, 0, -1};
      int dc[] = {1, 0, -1, 0};
      push(r + dr[i], c + dc[i], d);
    }
    rep(dr, -2, 3) rep(dc, -2, 3) push(r + dr, c + dc, d + 1);
  }
  int ans = dist[dh][dw];
  wt(ans == inf ? -1 : ans);
}
