#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> s(n);
  cin >> s;
  V<bool> dp(10001);
  dp[0] = true;
  rep(i, n) {
    rrep(j, 10001) if (j - s[i] >= 0 && dp[j - s[i]]) { dp[j] = true; }
  }
  rrep(i, 10001) if (i % 10 != 0 && dp[i]) {
    wt(i);
    return;
  }
  wt(0);
}
