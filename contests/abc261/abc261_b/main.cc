#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  bool ok = [] {
    ints(n);
    V<string> a(n);
    cin >> a;
    rep(i, n) rep(j, n) {
      if (i == j) continue;
      char x = a[i][j];
      char y = a[j][i];
      if (x == 'D' && y != 'D') return false;
      if (x == 'W' && y != 'L') return false;
      if (x == 'L' && y != 'W') return false;
    }
    return true;
  }();
  wt(ok ? "correct" : "incorrect");
}
