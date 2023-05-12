#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(h, w);
  V<string> a(h), b(h);
  cin >> a >> b;
  rep(di, h) rep(dj, w) {
    bool ok = true;
    rep(i, h) rep(j, w) if (a[i][j] != b[(i + di) % h][(j + dj) % w]) ok =
        false;
    if (ok) return true;
  }
  return false;
}
