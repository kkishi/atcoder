#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(int n, const V<pair<int, int>>& v) {
  V<int> dp(n + 1);
  for (auto [a, b] : v) {
    rep(j, n + 1 - a) chmax(dp[j + a], dp[j] + b);
  }
  int ans = 0;
  rep(i, n + 1) chmax(ans, dp[i] + n - i);
  return ans;
}

void Main() {
  ints(n);
  V<int> a(3), b(3);
  cin >> a >> b;
  rep(2) {
    V<pair<int, int>> v;
    rep(i, 3) if (a[i] < b[i]) v.pb({a[i], b[i]});
    n = Solve(n, v);
    swap(a, b);
  }
  wt(n);
}
