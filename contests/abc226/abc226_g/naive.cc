#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(i, t) {
    dbg(i);
    wt([] {
      V<int> a(6), b(6);
      rep(i, 5) cin >> a[i + 1];
      rep(i, 5) cin >> b[i + 1];
      vector c(6, vector(6, int(0)));
      return Fix([&](auto rec, int depth1, int depth2) -> bool {
        dbg(depth1, depth2, a, b);
        if (depth1 == 6) {
          return true;
        }
        if (depth2 == 6) {
          if (a[depth1] == 0) return rec(depth1 + 1, depth1 + 1);
          return false;
        }
        rep(i, min(a[depth1], b[depth2]) + 1) {
          a[depth1] -= i;
          b[depth2] -= i;
          b[depth2 - depth1] += i;
          c[depth1][depth2] = i;
          if (rec(depth1, depth2 + 1)) return true;
          c[depth1][depth2] = 0;
          b[depth2 - depth1] -= i;
          b[depth2] += i;
          a[depth1] += i;
        }
        return false;
      })(1, 1);
    }());
  }
}
