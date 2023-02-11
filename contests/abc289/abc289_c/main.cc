#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(m);
  rep(i, m) {
    ints(c);
    rep(c) {
      ints(x);
      a[i] |= 1 << (x - 1);
    }
  }
  int ans = 0;
  rep(mask, 1 << m) {
    int s = 0;
    rep(i, m) if (hasbit(mask, i)) s |= a[i];
    if (s == (1 << n) - 1) ++ans;
  }
  wt(ans);
}
