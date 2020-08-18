#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  strings(s);
  int n = s.size();
  vector<vector<mint>> dp(n + 1, vector<mint>(3));
  mint freedom = 1;
  rep(i, n) {
    if (s[i] == '?') {
      dp[i + 1][0] = dp[i][0] * 3 + freedom;
      dp[i + 1][1] = dp[i][1] * 3 + dp[i][0];
      dp[i + 1][2] = dp[i][2] * 3 + dp[i][1];
      freedom *= 3;
    } else {
      dp[i + 1] = dp[i];
      if (s[i] == 'A') {
        dp[i + 1][0] += freedom;
      } else if (s[i] == 'B') {
        dp[i + 1][1] += dp[i][0];
      } else if (s[i] == 'C') {
        dp[i + 1][2] += dp[i][1];
      }
    }
    dbg(i, dp[i + 1][2]);
  }
  wt(dp[n][2]);
}
