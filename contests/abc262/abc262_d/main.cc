#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint ans = 0;
  rep(i, 1, n + 1) {
    vector dp(i + 1, vector(i, mint(0)));
    dp[0][0] = 1;
    each(e, a) rrep(j, i) rep(k, i) dp[j + 1][(k + e) % i] += dp[j][k];
    ans += dp[i][0];
  }
  wt(ans);
}
