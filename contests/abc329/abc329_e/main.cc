#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n, m);
  strings(s, t);
  vector dp(n + 1, vector(m + 1, false));
  dp[0][0] = true;
  rep(i, n) {
    if (max(dp[i]) == 0) return false;
    rep(j, m) if (dp[i][j] && s[i] == t[j]) dp[i + 1][j + 1] = true;
    if (s[i] == t[0]) dp[i + 1][1] = true;
    if (dp[i][m]) rep(j, 1, m) if (s[i] == t[j]) dp[i + 1][j + 1] = true;
  }
  return dp[n][m];
}
