#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(n, d);

  map<int, int> fs = Factors(d);
  for (auto [k, _] : fs) {
    if (!set{2, 3, 5}.count(k)) {
      wt(0);
      return;
    }
  }

  vector dp(60, vector(38, vector(26, 0.0)));
  dp[0][0][0] = 1;
  rep(i, n) {
    vector ndp(60, vector(38, vector(26, 0.0)));
    rep(two, 60) rep(three, 38) rep(five, 26) {
      auto add = [&](int a, int b, int c) {
        ndp[min(59, two + a)][min(37, three + b)][min(25, five + c)] +=
            dp[two][three][five] / 6;
      };
      add(0, 0, 0);
      add(1, 0, 0);
      add(0, 1, 0);
      add(2, 0, 0);
      add(0, 0, 1);
      add(1, 1, 0);
    }
    swap(dp, ndp);
  }

  double ans = 0;
  rep(two, fs[2], 60) rep(three, fs[3], 38) rep(five, fs[5], 26) {
    ans += dp[two][three][five];
  }
  printf("%.9f\n", ans);
}
