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

  VV<int> dist(h, V<int>(w, big));
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
    each(nr, nc, adjacent(r, c)) push(nr, nc, d);
    rep(dr, -2, 3) rep(dc, -2, 3) push(r + dr, c + dc, d + 1);
  }
  int ans = dist[dh][dw];
  wt(ans == big ? -1 : ans);
}
