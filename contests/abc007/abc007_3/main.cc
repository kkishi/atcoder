#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"

void Main() {
  ints(R, C, sy, sx, gy, gx);
  V<string> c(R);
  cin >> c;
  Grid<int> g(R, C);
  rep(i, R) rep(j, C) if (c[i][j] != '#') g.Set(i, j, 1);
  wt(*g.Distance(sy - 1, sx - 1)[gy - 1][gx - 1]);
}
