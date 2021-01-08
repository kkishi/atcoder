#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  VV<int> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  VV<optional<mint>> dp(n, V<optional<mint>>(2));
  wt(Fix([&](auto rec, int n, int p, bool black) -> mint {
    optional<mint>& d = dp[n][black];
    if (!d) {
      mint w = 1;
      mint b = black ? 0 : 1;
      for (int c : to[n]) {
        if (c == p) continue;
        w *= rec(c, n, false);
        b *= rec(c, n, true);
      }
      d = w + b;
    }
    return *d;
  })(0, -1, false));
}
