#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

void Main() {
  ints(a, b);
  V<int> p = Primes(72);
  V<int> masks(b - a + 1);
  rep(i, a, b + 1) rep(j, sz(p)) if (i % p[j] == 0) masks[i - a] |= 1 << j;
  V<int> dp(1 << sz(p));
  dp[0] = 1;
  each(m, masks) {
    rrep(mask, 1 << sz(p)) {
      if ((mask & m) == 0) dp[mask | m] += dp[mask];
    }
  }
  wt(accumulate(dp));
}
