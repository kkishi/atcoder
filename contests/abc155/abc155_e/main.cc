#include <bits/stdc++.h>

#include "atcoder.h"

int dp[1000001][2];

void Main() {
  strings(n);

  dp[0][0] = 0;
  dp[0][1] = 1;
  rep(i, n.size()) {
    int digit = n[i] - '0';
    dp[i + 1][0] = min(dp[i][0] + digit,
                       min(dp[i][1] + (10 - digit), dp[i][1] + 1 + digit));
    dp[i + 1][1] = min(dp[i][0] + 1 + (9 - digit), dp[i][1] + (9 - digit));
  }
  wt(min(dp[n.size()][0], dp[n.size()][1] + 1));
}
