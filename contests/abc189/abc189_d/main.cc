#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  V<int> dp = {1, 1};
  rep(i, n) {
    V<int> ndp(2);
    rep(p, 2) rep(c, 2) ndp[(s[i] == "AND") ? (p & c) : (p | c)] += dp[p];
    swap(dp, ndp);
  }
  wt(dp[1]);
}
