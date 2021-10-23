#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  bool ok = true;
  rep(i, h) rep(I, i + 1, h) rep(j, w) rep(J, j + 1, w) {
    if (a[i][j] + a[I][J] > a[I][j] + a[i][J]) {
      ok = false;
    }
  }
  wt(ok);
}
