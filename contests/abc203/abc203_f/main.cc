#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  sort(a);

  int L = 40;
  vector dp(n, vector(L, big));
  dp[n - 1][0] = 0;
  using P = pair<int, int>;
  P ans = {big, big};
  rrep(i, n) {
    int idx = (lower_bound(all(a), div_ceil(a[i] + 1, 2)) - a.begin()) - 1;
    rep(j, L) {
      if (dp[i][j] == big) continue;
      if (i > 0) {
        if (dp[i][j] < k) {
          chmin(dp[i - 1][j], dp[i][j] + 1);
        }
      } else {
        int K = dp[i][j] + 1;
        if (K <= k) {
          chmin(ans, P{j, K});
        }
      }
      if (idx >= 0) {
        chmin(dp[idx][j + 1], dp[i][j]);
      } else {
        chmin(ans, P{j + 1, dp[i][j]});
      }
    }
  }
  wt(ans.first, ans.second);
}
