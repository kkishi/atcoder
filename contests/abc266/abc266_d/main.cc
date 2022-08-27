#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<pair<int, int>, int> mp;
  rep(n) {
    ints(t, x, a);
    mp[{t, x}] = a;
  }
  vector dp(5, -big);
  dp[0] = 0;
  rep(t, 100000) {
    vector ndp(5, -big);
    rep(i, 5) {
      if (dp[i] < 0) continue;
      rep(j, -1, 2) {
        int ni = i + j;
        if (ni < 0 || 5 <= ni) continue;
        chmax(ndp[ni], dp[i] + mp[{t + 1, ni}]);
      }
    }
    swap(dp, ndp);
  }
  wt(max(dp));
}
