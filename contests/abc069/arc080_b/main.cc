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
    if (i % 2 == 0) {
      rep(j, w) assign(i, j);
    } else {
      rrep(j, w) assign(i, j);
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (j) cout << " ";
      cout << grid[i][j];
    }
    cout << endl;
  }
}
