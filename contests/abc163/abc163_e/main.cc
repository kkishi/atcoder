#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<pair<int, int>> ai(n);
  rep(i, n) {
    cin >> ai[i].first;
    ai[i].second = i;
  }
  sort(ai, greater{});
  VV<int> dp(n + 1, V<int>(n + 1));
  rep(i, n) rep(j, i + 1) {
    auto [a, index] = ai[i];
    chmax(dp[i + 1][j + 1], dp[i][j] + a * abs(index - j));
    chmax(dp[i + 1][j], dp[i][j] + a * abs(index - (n - 1 - (i - j))));
  }
  wt(max(dp[n]));
}
