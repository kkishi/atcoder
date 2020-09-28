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
      int dr[] = {0, 1, 0, -1};
      int dc[] = {1, 0, -1, 0};
      rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || h <= nr || nc < 0 || w <= nc) continue;
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
