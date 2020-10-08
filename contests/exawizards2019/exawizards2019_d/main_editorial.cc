#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, x);
  V<int> s(n);
  cin >> s;
  sort(all(s), greater());
  vector dp(n + 1, vector(x + 1, mint(0)));
  dp[0][x] = 1;
  rep(i, n) rep(j, x + 1) {
    dp[i + 1][j % s[i]] += dp[i][j] / (n - i);
    dp[i + 1][j] += dp[i][j] * (n - 1 - i) / (n - i);
  }
  mint ans = 0;
  rep(i, x + 1) ans += dp[n][i] * i * mint::Fact(n);
  wt(ans);
}
