#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  wt(BinarySearch<double>(0, 1000000000, [&](double x) {
    V<double> b(n);
    rep(i, n) b[i] = a[i] - x;
    V<double> dp(n);
    dp[0] = b[0];
    dp[1] = max(b[1], b[0] + b[1]);
    rep(i, 2, n) dp[i] = b[i] + max(dp[i - 1], dp[i - 2]);
    return max(dp[n - 2], dp[n - 1]) > 0;
  }));
  V<int> sa = a;
  sort(sa);
  wt(sa[BinarySearch<int>(0, n, [&](int idx) {
    int x = sa[idx];
    V<int> b(n);
    rep(i, n) b[i] = a[i] < x ? -1 : 1;
    V<int> dp(n);
    dp[0] = b[0];
    dp[1] = max(b[1], b[0] + b[1]);
    rep(i, 2, n) dp[i] = b[i] + max(dp[i - 1], dp[i - 2]);
    return max(dp[n - 2], dp[n - 1]) > 0;
  })]);
}
