#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s);
  vector dp(n + 1, vector(s + 101, int(-1)));
  dp[0][0] = 0;
  V<int> a(n), b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
    rep(j, s) {
      if (dp[i][j] != -1) {
        dp[i + 1][j + a[i]] = 0;
        dp[i + 1][j + b[i]] = 1;
      }
    }
  }
  if (dp[n][s] == -1) {
    wt("No");
  } else {
    wt("Yes");
    string ans(n, ' ');
    int x = s;
    rrep(i, n) {
      if (dp[i + 1][x] == 0) {
        ans[i] = 'H';
        x -= a[i];
      } else {
        ans[i] = 'T';
        x -= b[i];
      }
    }
    wt(ans);
  }
}
