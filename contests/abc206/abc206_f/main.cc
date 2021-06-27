#include <bits/stdc++.h>

#include "atcoder.h"

void Solve() {
  ints(n);
  V<int> L(n), R(n);
  rep(i, n) cin >> L[i] >> R[i];
  vector dp(101, vector(101, int(-1)));
  auto rec = Fix([&](auto rec, int l, int r) -> int {
    int& d = dp[l][r];
    if (d == -1) {
      V<bool> seen(101);
      rep(i, n) if (l <= L[i] && R[i] <= r) {
        seen[rec(l, L[i]) ^ rec(R[i], r)] = true;
      }
      for (int i = 0;; ++i) {
        if (!seen[i]) {
          d = i;
          break;
        }
      }
    }
    return d;
  });
  wt(rec(1, 100) ? "Alice" : "Bob");
}

void Main() {
  ints(t);
  rep(t) Solve();
}
