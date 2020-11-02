#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s, t, w);
  int ans = s <= w && w <= t;
  rep(n - 1) {
    ints(a);
    w += a;
    ans += s <= w && w <= t;
  }
  wt(ans);
}
