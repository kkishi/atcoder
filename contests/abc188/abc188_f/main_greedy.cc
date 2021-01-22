#include <bits/stdc++.h>

#include "atcoder.h"

// This solution fails with handmade_04.txt. TODO to understand why once the
// input data is published.
void Main() {
  ints(x, y);
  int ans = big;
  for (int p2 = 0;; ++p2) {
    int z = x;
    rep(p2) z *= 2;
    // chmin(ans, p2 + abs(z - y));
    if (z > y * 2) break;
    int d = abs(y - z);
    dbg(x, y, p2, z, d);
    int cnt = d / (1LL << p2);
    d &= (1LL << p2) - 1;
    dbg(cnt, d);
    rep(i, p2 + 1) {
      if (hasbit(d, i)) {
        if (hasbit(d, i + 1)) {
          d += 1LL << i;
        } else {
          d -= 1LL << i;
        }
        ++cnt;
      }
      dbg(i, cnt, d);
    }
    dbg(cnt, d);
    assert(d == 0);
    chmin(ans, p2 + cnt + !!d);
  }
  wt(ans);
}
