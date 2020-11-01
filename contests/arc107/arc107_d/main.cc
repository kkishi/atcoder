#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(N, K);
  vector dp(N + 1, vector(N + 1, optional<mint>()));
  wt(Fix([&](auto rec, int n, int k) -> mint {
    if (k > n) return 0;
    if (k == n) return 1;
    if (n == 0 || k == 0) return 0;
    auto& d = dp[n][k];
    if (!d) {
      d = rec(n - 1, k - 1) + rec(n, k * 2);
    }
    return *d;
  })(N, K));
}
