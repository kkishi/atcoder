#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w);
  VV<int> a(h, V<int>(w));
  cin >> a;
  VV<optional<mint>> dp(h, V<optional<mint>>(w));
  auto rec = Fix([&](auto rec, int r, int c) -> mint {
    optional<mint>& d = dp[r][c];
    if (!d) {
      mint sum = 1;
      each(nr, nc, adjacent(r, c)) {
        if (!inside(nr, nc, h, w)) continue;
        if (a[nr][nc] <= a[r][c]) continue;
        sum += rec(nr, nc);
      }
      d = sum;
    }
    return *d;
  });
  mint ans = 0;
  rep(i, h) rep(j, w) ans += rec(i, j);
  wt(ans);
}
