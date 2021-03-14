#include <bits/stdc++.h>

#include "atcoder.h"
#include "primes.h"

void Main() {
  ints(a, b);
  V<int> p = Primes(72);
  VV<int> v(1 << sz(p));
  rep(i, a, b + 1) {
    int mask = 0;
    rep(j, sz(p)) if (i % p[j] == 0) mask |= 1 << j;
    v[mask].pb(i);
  }
  rep(i, 1 << sz(p)) if (sz(v[i])) dbg(i, sz(v[i]), v[i]);
  int rem = 0;
  const int N = sz(v[0]);
  rep(mask, 1, 1 << N) {
    bool ok = true;
    if (popcount(mask) > 1) {
      rep(i, N) rep(j, i + 1, N) {
        if (hasbit(mask, i) && hasbit(mask, j) && gcd(v[0][i], v[0][j]) != 1) {
          ok = false;
        }
      }
    }
    if (ok) ++rem;
  }
  dbg(rem);
  V<int> dp(1 << sz(p));
  dp[0] = rem;
  rep(i, 1 << sz(p)) {
    dp[i] = v[i].size();
    for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
      assert((j & i) == j);
      // if (j > (i ^ j)) continue;
      dp[i] += v[j].size() * dp[i ^ j];
      /*
      if (dp[j] * dp[i ^ j] > 0) {
        dbg(i, j, dp[j], dp[i ^ j]);
      }
      */
    }
    if (dp[i] > 0) dbg(i, dp[i]);
  }
  wt(accumulate(all(dp), int(0)) + 1);
}
