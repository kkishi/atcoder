#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

// This code is not complete.
void Main() {
  ints(n, m, l);
  vector dp(n + 1, vector(m + 1, vector(l + 1, optional<mint>())));
  auto rec = Fix([&](auto rec, int n, int m, int l) -> mint {
    if (n < 0) return 0;
    if (m < 0) return 0;
    if (n < m) return 0;
    if (m == 0) return 1;
    auto& ret = dp[n][m][l];
    if (!ret) {
      *ret = 0;
      for (int o = 1; o <= l; ++o) {
        *ret += rec(n - o, m - o, o) * mint::Perm(n, o - 1);
        *ret += rec(n - o, m - (n - 1), o) * mint::Perm(n, o) / 2;
      }
      // dbg(n, m, l, *ret);
    }
    return *ret;
  });
  mint ans = 0;
  ans += rec(n - l, m - l, l) * mint::Perm(n, l - 1);
  dbg(ans);
  ans += rec(n - l, m - (l - 1), l - 1) * mint::Perm(n, l) / 2;
  wt(ans);
}
