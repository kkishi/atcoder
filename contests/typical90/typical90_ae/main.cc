#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> w(n), b(n);
  cin >> w >> b;
  vector dp(51, vector(1300, int(-1)));
  auto rec = Fix([&](auto rec, int i, int j) -> int {
    int& d = dp[i][j];
    if (d == -1) {
      // Using set<int> makes this substantially slower (1.2s v.s. 400ms).
      V<bool> seen(100000);
      if (i >= 1) seen[rec(i - 1, j + i)] = true;
      for (int k = 1; k <= j / 2; ++k) seen[rec(i, j - k)] = true;
      for (int k = 0;; ++k)
        if (!seen[k]) {
          d = k;
          break;
        }
    }
    return d;
  });
  int x = 0;
  rep(i, n) x ^= rec(w[i], b[i]);
  wt(x ? "First" : "Second");
}
