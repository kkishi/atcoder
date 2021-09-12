#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(n, m, q);
  V<int> a(n), b(m);
  rep(q) {
    ints(t, x, y);
    if (t == 1) {
      a[x - 1] = y;
    } else {
      b[x - 1] = y;
    }
    int ans = 0;
    rep(i, n) rep(j, m) ans += max(a[i], b[j]);
    wt(ans);
  }
}
