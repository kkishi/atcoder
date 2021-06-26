#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  vector dp(n + 1, vector(n + 1, mint(0)));
  dp[0][0] = 1;
  mint ans = 0;
  rep(U, n) {
    int NU = U + 1;
    V<mint> ms(NU);
    rep(P, n) {
      ms[s[P] % NU] += dp[U][P];
      dp[NU][P + 1] += ms[s[P + 1] % NU];
    }
    ans += dp[NU][n];
  }
  wt(ans);
}
