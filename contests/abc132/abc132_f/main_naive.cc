#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);

  vector dp(k + 1, vector(n + 1, 0));
  vector sdp(k + 1, vector(n + 1, 0));
  dp[0][1] = 1;
  rep(i, k) {
    for (int j = 1; j <= n; ++j) {
      sdp[i][j] = sdp[i][j - 1] + dp[i][j];
    }
    for (int j = 1; j <= n; ++j) {
      dp[i + 1][j] = sdp[i][n / j];
    }
  }
  wt(accumulate(all(dp[k]), 0));
}
