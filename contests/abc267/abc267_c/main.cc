#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  int sum = 0;
  rep(i, m) sum += a[i] * (i + 1);
  int ans = sum;
  CumulativeSum1D c(a);
  rep(i, n - m) {
    sum -= c.Get(i, i + m - 1);
    sum += a[i + m] * m;
    chmax(ans, sum);
  }
  wt(ans);
}
