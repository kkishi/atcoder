#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  int sn = sz(s), tn = sz(t);
  vector dp(sn + 1, vector(tn + 1, -big));
  dp[0][0] = 0;
  rep(i, sn + 1) rep(j, tn + 1) {
    if (i < sn) chmax(dp[i + 1][j], dp[i][j]);
    if (j < tn) chmax(dp[i][j + 1], dp[i][j]);
    if (i < sn && j < tn) {
      if (s[i] != t[j]) {
        chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  }
  wt(dp[sn][tn]);
}
