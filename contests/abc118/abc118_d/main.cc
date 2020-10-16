#include <bits/stdc++.h>

#include "atcoder.h"

bool Less(const string& a, const string& b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

void Main() {
  const vector<int> cost = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  ints(n, m);

  vector<int> a(m);
  cin >> a;

  vector<string> dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    rep(j, m) {
      int k = i - cost[a[j]];
      if (k < 0 || dp[k] == "" && k != 0) continue;
      string d = char('0' + a[j]) + dp[k];
      if (Less(dp[i], d)) dp[i] = d;
    }
  }
  wt(dp[n]);
}
