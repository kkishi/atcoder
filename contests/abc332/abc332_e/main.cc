#include <bits/stdc++.h>

#include "atcoder.h"
#include "i128.h"

void Main() {
  ints(n, d);
  V<int> w(n);
  cin >> w;
  i128 sum = accumulate(w);
  vector s(1 << n, i128(0));
  rep(mask, 1 << n) rep(i, n) if (hasbit(mask, i)) s[mask] += w[i];
  vector dp(n + 1, vector(1 << n, i128(big) * i128(big)));
  dp[0][0] = 0;
  rep(i, d) {
    rep(mask, 1 << n) {
      for (int smask = mask;;) {
        smask = (smask - 1) & mask;
        i128 x = s[mask ^ smask];
        chmin(dp[i + 1][mask], dp[i][smask] + (x * d - sum) * (x * d - sum));
        if (smask == 0) break;
      }
    }
  }
  wt(dp[d][(1 << n) - 1] / (double)(d * d * d));
}
