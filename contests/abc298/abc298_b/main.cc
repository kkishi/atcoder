#include <bits/stdc++.h>

#include "atcoder_yn.h"
#include "rotate90.h"

bool Main() {
  ints(n);
  vector a(n, vector(n, int(0)));
  vector b(n, vector(n, int(0)));
  cin >> a >> b;
  rep(4) {
    a = Rotate90(a);
    bool ok = true;
    rep(i, n) rep(j, n) if (a[i][j] && !b[i][j]) ok = false;
    if (ok) return true;
  }
  return false;
}
