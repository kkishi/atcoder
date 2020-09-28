#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> l(k), r(k);
  rep(i, k) cin >> l[i] >> r[i];
  V<mint> dp(n * 3);
  dp[0] = 1;
  dp[1] = -1;
  mint cur = 0;
  rep(i, n) {
    cur += dp[i];
    rep(j, k) {
      dp[i + l[j]] += cur;
      dp[i + r[j] + 1] -= cur;
    }
  }
  wt(cur);
}
