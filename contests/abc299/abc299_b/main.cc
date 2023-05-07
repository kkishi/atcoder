#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t);
  V<int> c(n), r(n);
  cin >> c >> r;
  auto f = [&](int x) {
    int ma = -big;
    int ans;
    rep(i, n) if (c[i] == x && chmax(ma, r[i])) ans = i;
    wt(ans + 1);
  };
  each(e, c) if (e == t) {
    f(t);
    return;
  }
  f(c[0]);
}
