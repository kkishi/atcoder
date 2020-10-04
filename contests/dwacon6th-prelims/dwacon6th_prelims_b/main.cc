#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> x(n);
  cin >> x;

  V<mint> dp(n);
  rep(i, n - 1) dp[i + 1] = (i + 1) * dp[i] + mint::Fact(i);

  mint ans = 0;
  rep(i, n - 1) {
    mint a = x[i + 1] - x[i];
    mint b = dp[i + 1];
    int j = n - (i + 2);
    mint c = mint::Perm(n - 1, j);
    ans += a * b * c;
  }
  wt(ans);
}
