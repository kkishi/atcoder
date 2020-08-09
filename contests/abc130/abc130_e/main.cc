#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int main() {
  rd(int, n, m);
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  vector<int> t(m);
  rep(i, m) cin >> t[i];

  vector<vector<mint>> dp(n + 1, vector<mint>(m + 1));
  rep(i, n + 1) dp[i][0] = 1;
  rep(i, m + 1) dp[0][i] = 1;
  rep(i, n) rep(j, m) {
    dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1];
    if (s[i] != t[j]) dp[i + 1][j + 1] -= dp[i][j];
  }
  wt(dp[n][m]);
}
