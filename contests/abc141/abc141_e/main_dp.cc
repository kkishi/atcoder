#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int ans = 0;
  VV<int> dp(5001, V<int>(5001));
  rrep(i, n) rrep(j, n) if (s[i] == s[j]) {
    dp[i][j] = dp[i + 1][j + 1] + 1;
    chmax(ans, min(abs(i - j), dp[i][j]));
  }
  wt(ans);
}
