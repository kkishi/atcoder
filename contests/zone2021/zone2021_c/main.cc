#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  vector v(n, vector(5, int(0)));
  cin >> v;
  wt(BinarySearch<int>(0, big, [&](int x) {
    rep(i, 3) rep(j, 3) rep(k, 3) rep(l, 3) rep(m, 3) {
      vector dp(1 << 3, false);
      dp[0] = true;
      rep(J, n) {
        vector ndp = dp;
        rep(I, 3) {
          bool ok = true;
          if (i == I && v[J][0] < x) ok = false;
          if (j == I && v[J][1] < x) ok = false;
          if (k == I && v[J][2] < x) ok = false;
          if (l == I && v[J][3] < x) ok = false;
          if (m == I && v[J][4] < x) ok = false;
          if (ok) {
            rep(mask, 1 << 3) if (dp[mask]) ndp[mask | (1 << I)] = true;
          }
        }
        swap(dp, ndp);
      }
      if (dp[(1 << 3) - 1]) return true;
    }
    return false;
  }));
}
