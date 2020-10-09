#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, W);
  V<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];
  V<int> dp(W + 1, -1);
  dp[0] = 0;
  rep(i, n) rrep(j, W + 1 - w[i]) if (dp[j] != -1) {
    chmax(dp[j + w[i]], dp[j] + v[i]);
  }
  wt(*max_element(all(dp)));
}
