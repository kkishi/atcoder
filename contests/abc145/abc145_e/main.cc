#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, t);
  vector<pair<int, int>> f(n);
  rep(i, n) cin >> f[i].first >> f[i].second;
  sort(all(f));
  vector<int> dp(t + 3001);
  int ans = 0;
  rep(i, n) {
    for (int j = t - 1; j >= 0; --j) {
      dp[j + f[i].first] = max(dp[j + f[i].first], dp[j] + f[i].second);
      chmax(ans, dp[j + f[i].first]);
    }
  }
  wt(ans);
}
