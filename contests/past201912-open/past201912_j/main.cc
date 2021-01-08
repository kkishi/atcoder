#include <bits/stdc++.h>

#include "atcoder.h"
#include "grid.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;

  Grid<int> g(h, w);
  rep(i, h) rep(j, w) g.Set(i, j, a[i][j]);

  auto x = g.Distance(h - 1, w - 1);
  auto y = g.Distance(h - 1, 0);
  auto z = g.Distance(0, w - 1);

  int ans = big;
  rep(i, h) rep(j, w) chmin(ans, *x[i][j] + *y[i][j] + *z[i][j] - a[i][j] * 2);
  wt(ans);
}
