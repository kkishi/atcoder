#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  VV<int> v(n, V<int>(3));
  cin >> v;
  VV<int> dp(n + 1, V<int>(3, 0));
  rep(i, n) rep(j, 3) rep(k, 3) if (j != k) {
    chmax(dp[i + 1][k], dp[i][j] + v[i][k]);
  }
  wt(*max_element(all(dp[n])));
}
