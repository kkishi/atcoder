#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  vector dp(sz(s) + 1, V<int>(sz(t) + 1));
  vector p(sz(s) + 1, V<pair<int, int>>(sz(t) + 1));
  rep(i, sz(s)) rep(j, sz(t)) {
    if (s[i] == t[j])
      if (chmax(dp[i + 1][j + 1], dp[i][j] + 1)) {
        p[i + 1][j + 1] = {i, j};
      }
    if (chmax(dp[i + 1][j + 1], dp[i][j + 1])) {
      p[i + 1][j + 1] = {i, j + 1};
    }
    if (chmax(dp[i + 1][j + 1], dp[i + 1][j])) {
      p[i + 1][j + 1] = {i + 1, j};
    }
  }
  if (dp[sz(s)][sz(t)] == 0) {
    wt("");
    return;
  }
  string ans;
  int i = sz(s), j = sz(t);
  while (i != 0 && j != 0) {
    auto [pi, pj] = p[i][j];
    if (pi == i - 1 && pj == j - 1) ans += s[i - 1];
    i = pi;
    j = pj;
  }
  reverse(ans);
  wt(ans);
}
