#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<int> ng;
  rep(3) {
    ints(ngi);
    ng.insert(ngi);
  }
  if (ng.count(n)) {
    wt("NO");
    return;
  }
  V<bool> dp(n + 1);
  dp[n] = true;
  rep(100) {
    V<bool> ndp(n + 1);
    rep(i, n) rep(j, 1, 4) if (!ng.count(i) && i + j <= n && dp[i + j]) {
      ndp[i] = true;
    }
    swap(dp, ndp);
    if (dp[0]) {
      wt("YES");
      return;
    }
  }
  wt("NO");
}
