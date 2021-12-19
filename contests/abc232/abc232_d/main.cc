#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  vector dp(h, vector(w, -big));
  dp[0][0] = 1;
  rep(i, h) rep(j, w) {
    if (i + 1 < h && c[i + 1][j] == '.') chmax(dp[i + 1][j], dp[i][j] + 1);
    if (j + 1 < w && c[i][j + 1] == '.') chmax(dp[i][j + 1], dp[i][j] + 1);
  }
  int ans = -big;
  each(e, dp) each(f, e) chmax(ans, f);
  wt(ans);
}
