#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  cin >> a;
  vector b(n, vector(n, false));
  ints(m);
  rep(m) {
    ints(x, y);
    --x, --y;
    b[x][y] = b[y][x] = true;
  }
  V<int> idx(n);
  iota(all(idx), int(0));
  int ans = big;
  do {
    int sum = 0;
    bool ok = true;
    rep(i, n) {
      int I = idx[i];
      sum += a[I][i];
      if (i + 1 < n) {
        int J = idx[i + 1];
        if (b[I][J]) ok = false;
      }
    }
    if (ok) chmin(ans, sum);
  } while (next_permutation(all(idx)));
  if (ans == big) ans = -1;
  wt(ans);
}
