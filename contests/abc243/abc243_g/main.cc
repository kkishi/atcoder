#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_sqrt.h"

void Main() {
  const int N = 1000000;
  vector dp(N, int(0));
  vector ddp(N, int(0));
  ddp[1] = 1;
  rep(i, 1, N) {
    dp[i] = dp[i - 1] + ddp[i];
    if (int j = i * i; j < N) ddp[j] = dp[i];
  }
  ints(t);
  rep(t) {
    ints(x);
    int sx = IntSqrt(x);
    int ssx = IntSqrt(sx);
    int ans = 0;
    rep(i, 1, ssx + 1) ans += (sx - i * i + 1) * dp[i];
    wt(ans);
  }
}
