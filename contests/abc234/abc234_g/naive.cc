#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  vector dp(n + 1, mint(0));
  dp[0] = 1;
  rep(i, n) {
    int ma = a[i];
    int mi = a[i];
    rrep(j, i) {
      chmax(ma, a[j]);
      chmin(mi, a[j]);
      dp[i + 1] += (ma - mi) * dp[j];
    }
  }
  wt(dp[n]);
}
