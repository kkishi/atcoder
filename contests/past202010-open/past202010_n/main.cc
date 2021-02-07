#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> dp(1 << 12);
  dp[0] = 1;
  rep(row, 18) {
    strings(s);
    V<int> ndp(1 << 12);
    rep(p2, 1 << 6) {
      bool ok = true;
      rep(i, 6) if (s[i] != '?' && (s[i] == '1' != hasbit(p2, i))) ok = false;
      if (!ok) continue;
      rep(p0, 1 << 6) rep(p1, 1 << 6) {
        bool ok = true;
        // Check p1
        rep(i, 6) {
          int x = hasbit(p0, i) + hasbit(p1, i) + hasbit(p2, i);
          if (i > 0) x += hasbit(p1, i - 1);
          if (i + 1 < 6) x += hasbit(p1, i + 1);
          if (hasbit(p1, i) != (x >= 3)) ok = false;
        }
        // Check p2
        rep(i, 6) {
          int x = hasbit(p1, i) + hasbit(p2, i);
          if (i > 0) x += hasbit(p2, i - 1);
          if (i + 1 < 6) x += hasbit(p2, i + 1);
          if (hasbit(p2, i)) {
            if (x < (row == 17 ? 3 : 2)) ok = false;
          } else {
            if (x >= 3) ok = false;
          }
        }
        if (ok) ndp[(p1 << 6) | p2] += dp[(p0 << 6) | p1];
      }
    }
    swap(dp, ndp);
  }
  wt(accumulate(all(dp), int(0)));
}
