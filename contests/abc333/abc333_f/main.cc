#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  vector dp(n + 1, mint(0));
  dp[0] = 1;
  rep(i, 1, n) {
    mint sum = 0;
    rep(j, 1, i + 1) sum += mint::Comb(i, j) * dp[i - j];
    mint x = 1 / mint(2).Pow(i + 1);
    dp[i] = x * sum / (1 - x);
  }

  V<mint> ans;
  rep(i, n) {
    mint sum = 0;
    rep(j, i + 1) sum += mint::Comb(i, j) * dp[n - 1 - j];
    ans.eb(sum / mint(2).Pow(i));
  }
  wt(ans);
}
