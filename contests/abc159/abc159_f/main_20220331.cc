#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, s);
  V<int> a(n);
  cin >> a;
  mint ans = 0;
  V<mint> dp(3001);
  rep(i, n) {
    rrep(j, a[i], s + 1) dp[j] += dp[j - a[i]];
    dp[a[i]] += 1 + i;
    ans += dp[s];
  }
  wt(ans);
}
