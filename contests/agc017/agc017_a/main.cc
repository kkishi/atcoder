#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, p);
  V<int> dp = {1, 0};
  rep(n) {
    ints(a);
    if (even(a)) {
      dp = {dp[0] * 2, dp[1] * 2};
    } else {
      dp = {dp[0] + dp[1], dp[1] + dp[0]};
    }
  }
  wt(dp[p]);
}
