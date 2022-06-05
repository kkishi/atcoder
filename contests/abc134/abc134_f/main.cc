#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

mint Solve(int n, int k) {
  vector dp(n + 1, vector((n + 5) * (n + 5) + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    vector ndp(n + 1, vector((n + 5) * (n + 5) + 1, mint(0)));
    rep(j, i + 1) rep(k, n * n + 1) {
      mint x = dp[j][k];
      if (x == 0) continue;
      int rem = i - j;
      // ee
      ndp[j + 1][k + rem * 2] += x;
      // uu
      if (rem > 0) {
        ndp[j + 2][k + (rem - 1) * 2] += x * rem * rem;
      }
      // ud, du
      if (rem > 0) {
        ndp[j + 1][k + rem * 2] += x * rem * 2;
      }
      // dd
      ndp[j][k + (rem + 1) * 2] += x;
    }
    swap(dp, ndp);
  }
  return dp[n][k];
}

mint Naive(int n, int k) {
  V<int> p(n);
  iota(all(p), 0);
  mint ans = 0;
  do {
    int sum = 0;
    rep(i, n) sum += abs(p[i] - i);
    if (sum == k) ++ans;
  } while (next_permutation(all(p)));
  return ans;
}

void Main() {
  ints(n, k);
  wt(Solve(n, k));
}
