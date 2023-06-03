#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  strings(s);
  mint ans = 0;
  V<mint> dp(n);
  rep(m, 1, n) {
    if (n % m) continue;
    int l = n / m;
    mint cnt = 1;
    rep(i, m) {
      bool free = true;
      rep(j, l) if (s[i + j * m] == '.') free = false;
      if (free) cnt *= 2;
    }
    dp[m] += cnt;
    ans += dp[m];
    for (int i = m * 2; i < n; i += m) {
      if (n % i == 0) {
        dp[i] -= dp[m];
      }
    }
  }
  wt(ans);
}
