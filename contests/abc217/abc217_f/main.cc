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
  vector dp(N + 1, vector(N + 1, vector(2, mint(0))));
  vector sn(N + 1, vector(N + 1, vector(2, false)));
  wt(Fix([&](auto rec, int l, int r, bool isLeft) -> mint {
    if (l == r) return 1;
    if (sn[l][r][isLeft]) return dp[l][r][isLeft];
    sn[l][r][isLeft] = true;
    mint ret = 0;
    if (ok[l][r - 1]) ret += rec(l + 1, r - 1, false);
    if (!isLeft) {
      for (int L = l + 2; L < r; L += 2) {
        int A = (L - l) / 2;
        int B = (r - L) / 2;
        ret += rec(l, L, true) * rec(L, r, false) * mint::Comb(A + B, A);
      }
    }
    return dp[l][r][isLeft] = ret;
  })(0, N, false));
}
