#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, ma, mb);
  V<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
  const int maxi = 10 * n;
  const int inf = numeric_limits<int>::max() / 10;
  VV<int> dp(maxi + 1, V<int>(maxi + 1, inf));
  dp[0][0] = 0;
  rep(i, n) {
    rrep(ai, a[i], maxi + 1) rrep(bi, b[i], maxi + 1) {
      chmin(dp[ai][bi], dp[ai - a[i]][bi - b[i]] + c[i]);
    }
  }
  int ans = inf;
  for (int i = 1; i * max(ma, mb) <= maxi; ++i) {
    chmin(ans, dp[ma * i][mb * i]);
  }
  wt(ans == inf ? -1 : ans);
}
