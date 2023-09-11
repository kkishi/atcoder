#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int L = 1;
  rep(i, 1, 9) L = lcm(L, i);
  ints(n, x, y);
  V<int> p(n - 1), t(n - 1);
  rep(i, n - 1) cin >> p[i] >> t[i];
  V<int> ans;
  rep(offset, L) {
    int curr = offset + x;
    rep(i, n - 1) {
      int d = div_ceil(curr, p[i]);
      curr = d * p[i] + t[i];
    }
    ans.eb(curr);
  }
  ints(q);
  rep(q) {
    ints(qi);
    int rem = qi % L;
    wt(qi - rem + ans[rem] + y);
  }
}
