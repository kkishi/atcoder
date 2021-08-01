#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(p);
  mint ans = 1;
  int P = p - 1;
  V<int> d = Divisors(P);
  map<int, mint> dp;
  rrep(i, sz(d)) {
    int D = d[i];
    dp[D] = P / D;
    rep(j, i + 1, sz(d)) {
      int E = d[j];
      if (E % D == 0) {
        dp[D] -= dp[E];
      }
    }
  }
  each(k, v, dp) ans += P / k * v;
  wt(ans);
}
