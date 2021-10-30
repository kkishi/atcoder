#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  vector b(n, vector(m, int(0)));
  cin >> b;
  bool ok = true;
  rep(i, n - 1) rep(j, m) if (b[i + 1][j] != b[i][j] + 7) ok = false;
  rep(i, n) rep(j, m - 1) {
    if ((b[i][j] - 1) / 7 != (b[i][j + 1] - 1) / 7) ok = false;
    if (b[i][j + 1] != b[i][j] + 1) ok = false;
  }
  wt(ok);
}
