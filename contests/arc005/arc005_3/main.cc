#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  deque<tuple<int, int, int>> que;
  vector dist(h, vector(w, big));
  rep(i, h) rep(j, w) if (c[i][j] == 's') {
    dist[i][j] = 0;
    que.eb(i, j, 0);
  }
  while (!que.empty()) {
    auto [i, j, d] = que.front();
    que.pop_front();
    if (c[i][j] == 'g') {
      wt("YES");
      return;
    }
    each(ni, nj, adjacent(i, j)) {
      if (inside(ni, nj, h, w)) {
        int x = c[ni][nj];
        if (x == '#') {
          if (d < 2 && chmin(dist[ni][nj], d + 1)) {
            que.eb(ni, nj, d + 1);
          }
        } else {
          if (chmin(dist[ni][nj], d)) {
            que.emplace_front(ni, nj, d);
          }
        }
      }
    }
  }
  wt("NO");
}
