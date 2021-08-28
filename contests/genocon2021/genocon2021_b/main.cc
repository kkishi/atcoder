#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  int n = sz(s), m = sz(t);
  vector dp(n + 1, vector(m + 1, -big));
  vector pr(n + 1, vector(m + 1, pair<int, int>()));
  dp[0][0] = 0;
  rep(i, n + 1) rep(j, m + 1) {
    if (i < n && j < m) {
      int c = s[i] == t[j] ? 1 : -3;
      if (chmax(dp[i + 1][j + 1], dp[i][j] + c)) pr[i + 1][j + 1] = {i, j};
    }
    if (i < n) {
      if (chmax(dp[i + 1][j], dp[i][j] - 5)) pr[i + 1][j] = {i, j};
    }
    if (j < m) {
      if (chmax(dp[i][j + 1], dp[i][j] - 5)) pr[i][j + 1] = {i, j};
    }
  }
  each(e, dp) dbg(e);
  dbg(dp[n][m]);
  string S, T;
  int i = n, j = m;
  while (i > 0 || j > 0) {
    dbg(i, j, dp[i][j]);
    auto [I, J] = pr[i][j];
    if (I == i) {
      S += '-';
      T += t[J];
    } else if (J == j) {
      S += s[I];
      T += '-';
    } else {
      S += s[I];
      T += t[J];
    }
    i = I;
    j = J;
  }
  reverse(all(S));
  reverse(all(T));
  wt(S);
  wt(T);
}
