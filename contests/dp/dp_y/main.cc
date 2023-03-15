#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w, n);
  V<int> r(n + 1), c(n + 1);
  rep(i, n) cin >> r[i] >> c[i];
  r[n] = h, c[n] = w;
  V<bool> seen(n + 1);
  V<mint> memo(n + 1);
  wt(Fix([&](auto rec, int i) -> mint {
    mint& m = memo[i];
    if (!seen[i]) {
      seen[i] = true;
      auto f = [&](int dr, int dc) { return mint::Comb(dr + dc, dr); };
      m = f(r[i] - 1, c[i] - 1);
      rep(j, n) if (j != i && r[j] <= r[i] && c[j] <= c[i]) {
        m -= rec(j) * f(r[i] - r[j], c[i] - c[j]);
      }
    }
    return m;
  })(n));
}
