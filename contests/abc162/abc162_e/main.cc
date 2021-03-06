#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  vector<mint> dp(k + 1);
  for (int i = k; i >= 1; --i) {
    dp[i] = mint(k / i).Pow(n);
    for (int j = 2; i * j <= k; ++j) {
      dp[i] -= dp[i * j];
    }
  }
  mint ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans += dp[i] * i;
  }
  wt(ans);
}
