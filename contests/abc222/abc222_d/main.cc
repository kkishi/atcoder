#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  vector dp(n + 1, vector(3001, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    mint sum = 0;
    rep(j, 3001) {
      sum += dp[i][j];
      if (a[i] <= j && j <= b[i]) {
        dp[i + 1][j] = sum;
      }
    }
  }
  wt(accumulate(dp[n]));
}
