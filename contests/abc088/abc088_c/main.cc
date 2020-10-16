#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  VV<int> c(3, V<int>(3));
  cin >> c;
  bool ok = true;
  rep(i, 2) rep(j, 2) {
    if (c[i + 1][j] - c[i + 1][j + 1] != c[0][j] - c[0][j + 1]) ok = false;
    if (c[j][i + 1] - c[j + 1][i + 1] != c[j][0] - c[j + 1][0]) ok = false;
  }
  wt(ok);
}
