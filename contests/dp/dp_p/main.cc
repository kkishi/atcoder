#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  Graph to(n);
  to.Read();
  vector dp(n, vector(2, optional<mint>()));
  auto rec = Fix([&](auto rec, int n, int p, bool b) -> mint {
    auto& d = dp[n][b];
    if (!d) {
      d = 1;
      for (int c : to[n]) {
        if (c == p) continue;
        mint cd = rec(c, n, false);
        if (!b) cd += rec(c, n, true);
        *d *= cd;
      }
    }
    return *d;
  });
  wt(rec(0, -1, false) + rec(0, -1, true));
}
