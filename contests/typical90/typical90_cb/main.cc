#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, d);
  V<int> a(n);
  cin >> a;
  int ans = 0;
  rep(mask, 1LL << n) {
    int x = 0;
    rep(i, n) if (hasbit(mask, i)) x |= a[i];
    int y = 1LL << (d - popcount(x));
    if (even(popcount(mask))) {
      ans += y;
    } else {
      ans -= y;
    }
  }
  wt(ans);
}
