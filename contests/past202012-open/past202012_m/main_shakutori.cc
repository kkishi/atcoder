#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, l);
  V<int> a(n);
  cin >> a;
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  wt(BinarySearch<int>(0, l + 1, [&](int x) {
    V<bool> dp(n + 1);
    int lo = 0, hi = 0, cnt = 0;
    rep(i, n) {
      while (s[i + 1] - s[lo] > l) {
        cnt -= dp[lo];
        ++lo;
      }
      while (s[i + 1] - s[hi] >= x) {
        cnt += dp[hi];
        ++hi;
      }
      if (lo == 0) {
        dp[i + 1] = s[i + 1] >= x;
      } else {
        dp[i + 1] = cnt > 0;
      }
    }
    // Weirdly, "return dp[n];" causes a use-after-free error.
    return dp[n] == true;
  }));
}
