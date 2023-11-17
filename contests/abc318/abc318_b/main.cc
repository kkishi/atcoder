#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector g(101, vector(101, int(0)));
  rep(n) {
    ints(a, b, c, d);
    rep(i, a, b) rep(j, c, d) g[i][j] = 1;
  }
  int ans = 0;
  each(e, g) ans += accumulate(e);
  wt(ans);
}
