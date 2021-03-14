#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, m, k);
  V<bool> ng(n + 1);
  rep(k) {
    ints(a);
    ng[a] = true;
  }
  int c = 0;
  rep(i, n + 1) {
    if (ng[i]) {
      ++c;
      if (c == m) {
        wt(-1);
        return;
      }
    } else {
      c = 0;
    }
  }
  wt(BinarySearch<double>(1e12, 0, [&](double x) {
    V<double> dp(n + 1);
    double sum = 0;
    rrep(i, n) {
      if (ng[i]) {
        dp[i] = x;
      } else {
        dp[i] = 1 + sum / m;
      }
      sum -= (i + m) >= n ? 0 : dp[i + m];
      sum += dp[i];
    }
    return x > dp[0];
  }));
}
