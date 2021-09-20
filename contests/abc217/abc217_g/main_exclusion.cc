#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  int q = n / m;
  int r = n % m;
  map<int, int> M;
  M[q + 1] = r;
  M[q] = m - r;
  vector dp(n + 1, mint(1));
  rep(i, 1, n + 1) {
    each(k, v, M) dp[i] *= mint::Perm(i, k).Pow(v);
    rep(j, 1, i) dp[i] -= mint::Perm(i, j) * dp[j];
    dp[i] /= mint::Fact(i);
    wt(dp[i]);
  }
}
