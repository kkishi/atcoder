#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, c);
  vector a(r, vector(c - 1, int(0)));
  vector b(r - 1, vector(c, int(0)));
  cin >> a >> b;
  vector dist(r, vector(c, vector(2, big)));
  dist[0][0][0] = 0;
  low_priority_queue<tuple<int, int, int, int>> que;
  que.emplace(0, 0, 0, 0);
  auto push = [&](int d, int R, int C, int S) {
    if (!inside(R, C, r, c)) return;
    if (chmin(dist[R][C][S], d)) que.emplace(d, R, C, S);
  };
  while (!que.empty()) {
    auto [d, R, C, S] = que.top();
    que.pop();
    if (d > dist[R][C][S]) continue;
    if (S == 1) {
      push(d + 1, R - 1, C, 1);
      push(d, R, C, 0);
    } else {
      push(d + 1, R, C, 1);
      push(d + b[R][C], R + 1, C, 0);
      push(d + a[R][C], R, C + 1, 0);
      push(d + a[R][C - 1], R, C - 1, 0);
    }
  }
  wt(dist[r - 1][c - 1][0]);
}
