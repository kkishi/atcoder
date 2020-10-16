#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"

void Main() {
  ints(H, W);
  vector<string> m(H);
  cin >> m;

  Grid<int> grid(H, W);
  rep(r, H) rep(c, W) if (m[r][c] == '.') grid.Set(r, c, 1);

  int ans = 0;
  rep(sr, H) rep(sc, W) if (m[sr][sc] == '.') {
    VV<optional<int>> dist = grid.Distance(sr, sc);
    rep(r, H) rep(c, W) if (optional<int> d = dist[r][c]; d) chmax(ans, *d);
  }
  wt(ans);
}
