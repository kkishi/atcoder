#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  ints(a, b, c, d, e, f);
  set<pair<int, int>> st;
  rep(m) {
    ints(x, y);
    st.insert({x, y});
  }
  map<pair<int, int>, mint> dp;
  dp[{0, 0}] = 1;
  rep(n) {
    map<pair<int, int>, mint> ndp;
    each(p, v, dp) {
      auto inc = [&](int x, int y) -> void {
        if (st.count({x, y})) return;
        ndp[{x, y}] += v;
      };
      auto [x, y] = p;
      inc(x + a, y + b);
      inc(x + c, y + d);
      inc(x + e, y + f);
    }
    swap(dp, ndp);
  }
  mint ans = 0;
  each(_, c, dp) ans += c;
  wt(ans);
}
