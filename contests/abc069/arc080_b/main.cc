#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, n);
  V<int> a(n);
  cin >> a;
  int i = 0;
  VV<int> grid(h, V<int>(w));
  auto assign = [&](int r, int c) {
    while (a[i] == 0) ++i;
    grid[r][c] = i + 1;
    --a[i];
  };
  rep(i, h) {
    if (even(i)) {
      rep(j, w) assign(i, j);
    } else {
      rrep(j, w) assign(i, j);
    }
  }
  rep(i, h) wt(grid[i]);
}
