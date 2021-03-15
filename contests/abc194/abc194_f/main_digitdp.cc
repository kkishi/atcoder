#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(n);
  const int N = sz(n);
  V<int> v;
  each(e, n) {
    if (isdigit(e)) {
      v.pb(e - '0');
    } else {
      v.pb(e - 'A' + 10);
    }
  }
  ints(k);

  // Digit DP
  vector dp(N + 1, vector(2, vector(2, vector(18, mint(0)))));
  dp[0][0][0][0] = 1;
  int st = 0;
  rep(i, N) {
    rep(isless, 2) rep(hasnonzero, 2) rep(used, k + 1) {
      // isless, hasnonzero: state after constructing [0, i].
      mint x = dp[i][isless][hasnonzero][used];
      if (x == 0) continue;
      auto cnt = [&st](int newuse) { return popcount(st | (1 << newuse)); };
      if (isless) {
        if (hasnonzero) {
          dp[i + 1][1][1][used] += x * used;
          dp[i + 1][1][1][used + 1] += x * (16 - used);
        } else {
          // Leading zeros
          assert(used == 0);
          assert(x == 1);
          dp[i + 1][1][0][0] += 1;   // Zero
          dp[i + 1][1][1][1] += 15;  // Non-zero
        }
      } else {
        // Less than v[i]
        rep(j, v[i]) {
          if (j == 0) {
            dp[i + 1][1][hasnonzero][hasnonzero ? cnt(j) : 0] += x;
          } else {
            dp[i + 1][1][1][cnt(j)] += x;
          }
        }
        // Equal to v[i]
        dp[i + 1][0][1][cnt(v[i])] += x;
      }
    }
    st |= 1 << v[i];
  }
  mint ans = 0;
  rep(i, 2) rep(j, 2) ans += dp[N][i][j][k];
  wt(ans);
}
