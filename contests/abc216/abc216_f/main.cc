#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<pair<int, int>> v;
  rep(i, n) v.eb(a[i], b[i]);
  sort(v);
  int N = 5000;
  vector dp(N + 1, mint(0));
  dp[0] = 1;
  mint ans = 0;
  each(a, b, v) {
    rrep(j, N + 1) {
      int k = j - b;
      if (k >= 0) {
        dp[j] += dp[k];
        if (j <= a) {
          ans += dp[k];
        }
      }
    }
  }
  wt(ans);
}
