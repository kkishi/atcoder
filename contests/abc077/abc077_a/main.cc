#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  bool ok = true;
  V<string> c(2);
  cin >> c;
  rep(i, 2) rep(j, 3) if (c[1 - i][2 - j] != c[i][j]) ok = false;
  wt(ok ? "YES" : "NO");
}
