#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, x);
  V<int> s(n);
  cin >> s;
  vector dp(x + 1, vector(n + 1, mint(0)));
  dp[x][n] = 1;
  rrep(i, x + 1) {
    rrep(j, 1, n + 1) if (dp[i][j] != 0) {
      int x = 0;
      rep(k, n) {
        if (s[k] <= i) {
          dp[i % s[k]][j - 1] += dp[i][j];
        } else {
          ++x;
        }
      }
      dp[i][j - 1] += dp[i][j] * max(0, x - (n - j));
    }
  }
  mint ans = 0;
  rep(i, x + 1) ans += dp[i][0] * i;
  wt(ans);
}
