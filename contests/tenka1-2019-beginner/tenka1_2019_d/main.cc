#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sa = accumulate(a);
  mint ans = mint(3).Pow(n);
  {
    V<mint> dp(sa + 1);
    dp[0] = 1;
    each(e, a) rrep(i, sa + 1) {
      mint x = dp[i];
      if (x == 0) continue;
      dp[i + e] += x;
      dp[i] += x;
    }
    ans -= accumulate(dp.begin() + div_ceil(sa, 2), dp.end(), mint(0)) * 3;
  }
  if (even(sa)) {
    V<mint> dp(sa + 1);
    dp[0] = 1;
    each(e, a) rrep(i, sa + 1) {
      mint x = dp[i];
      if (x == 0) continue;
      dp[i + e] += x;
    }
    ans += dp[sa / 2] * 3;
  }
  wt(ans);
}
