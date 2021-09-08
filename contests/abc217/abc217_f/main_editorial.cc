#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  int N = n * 2;
  vector ok(N, vector(N, false));
  rep(m) {
    ints(a, b);
    --a, --b;
    ok[a][b] = ok[b][a] = true;
  }
  vector dp(N + 1, vector(N + 1, mint(0)));
  vector sn(N + 1, vector(N + 1, false));
  wt(Fix([&](auto rec, int l, int r) -> mint {
    if (l == r) return 1;
    if (sn[l][r]) return dp[l][r];
    sn[l][r] = true;
    mint ret = 0;
    for (int m = l + 1; m < r; m += 2) {
      if (!ok[l][m]) continue;
      int L = ((m + 1) - l) / 2;
      int R = (r - (m + 1)) / 2;
      ret += rec(l + 1, m) * rec(m + 1, r) * mint::Comb(L + R, L);
    }
    return dp[l][r] = ret;
  })(0, N));
}
