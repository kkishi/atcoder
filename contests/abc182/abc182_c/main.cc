#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> d;
  while (n) {
    d.push_back(n % 10);
    n /= 10;
  }
  reverse(all(d));
  int l = sz(d);
  int ans = l;
  rep(s, 1 << l) {
    int x = 0;
    rep(i, l) if (hasbit(s, i))(x *= 10) += d[i];
    if (x % 3 == 0) chmin(ans, l - popcount(s));
  }
  if (ans == l) {
    wt(-1);
  } else {
    wt(ans);
  }
}
