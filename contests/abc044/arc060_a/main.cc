#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n, a);
  V<int> x(n);
  cin >> x;
  VV<int> dp(n + 1, V<int>(n * 50 + 1));
  dp[0][0] = 1;
  rep(i, n) rrep(k, i + 1) rep(j, x[i], sz(dp[i])) {
    dp[k + 1][j] += dp[k][j - x[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n && i * a < sz(dp[i]); ++i) {
    ans += dp[i][i * a];
  }
  wt(ans);
}
