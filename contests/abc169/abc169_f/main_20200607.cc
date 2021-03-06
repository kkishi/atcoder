#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

int a[3000];

using mint = ModInt<998244353>;

void Main() {
  ints(n, s);
  rep(i, n) cin >> a[i];
  vector<mint> dp(s + 1);
  dp[0] = 1;
  rep(i, n) {
    vector<mint> next(s + 1);
    for (int j = 0; j <= s; ++j) {
      next[j] += dp[j] * 2;
      int k = j + a[i];
      if (k <= s) {
        next[k] += dp[j];
      }
    }
    swap(dp, next);
  }
  wt(dp[s]);
}
