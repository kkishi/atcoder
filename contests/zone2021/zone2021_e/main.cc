#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w - 1, int(0)));
  vector b(h - 1, vector(w, int(0)));
  cin >> a >> b;
  vector dist(h, vector(w, vector(2, big)));
  low_priority_queue<tuple<int, int, int, int>> que;
  auto push = [&](int d, int r, int c, int s) {
    if (!inside(r, c, h, w)) return;
    if (chmin(dist[r][c][s], d)) que.emplace(d, r, c, s);
  };
  push(0, 0, 0, 0);
  while (!que.empty()) {
    auto [d, r, c, s] = que.top();
    que.pop();
    if (d > dist[r][c][s]) continue;
    if (s == 1) {
      push(d + 1, r - 1, c, 1);
      push(d, r, c, 0);
    } else {
      push(d + 1, r, c, 1);
      push(d + b[r][c], r + 1, c, 0);
      push(d + a[r][c], r, c + 1, 0);
      push(d + a[r][c - 1], r, c - 1, 0);
    }
  }
  wt(dist[h - 1][w - 1][0]);
}
