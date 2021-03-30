#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> ans;
  rep(x, n) {
    int mini = big;
    rep(j, 1, n + 1) {
      int y = x;
      rep(j) y = a[y] - 1;
      if (y == x) chmin(mini, j);
    }
    ans.pb(mini);
  }
  wt(ans);
}
