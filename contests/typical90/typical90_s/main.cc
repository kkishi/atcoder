#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int N = 2 * n;
  V<int> a(N);
  cin >> a;
  vector dp(N + 1, vector(N + 1, big));
  wt(Fix([&](auto rec, int l, int r) -> int {
    int len = r - l;
    if (len == 2) return abs(a[l + 1] - a[l]);
    int& d = dp[l][r];
    if (d != big) return d;
    for (int m = l + 2; m < r; m += 2) {
      chmin(d, rec(l, m) + rec(m, r));
    }
    chmin(d, rec(l + 1, r - 1) + abs(a[l] - a[r - 1]));
    return d;
  })(0, N));
}
