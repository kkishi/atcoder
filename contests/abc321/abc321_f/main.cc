#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(q, k);
  vector dp(5001, mint(0));
  dp[0] = 1;
  rep(q) {
    rd(char, op);
    ints(x);
    if (op == '+') {
      rrep(i, x, 5001) dp[i] += dp[i - x];
    } else {
      rep(i, x, 5001) dp[i] -= dp[i - x];
    }
    wt(dp[k]);
  }
}
