#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "count.h"

void Main() {
  ints(n, m, k);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  V<int> c(m), d(m);
  rep(i, m) cin >> c[i] >> d[i];
  double x = BinarySearch<double>(0, 2.0, [&](double x) {
    V<double> A;
    rep(i, n) A.eb(a[i] - x * (a[i] + b[i]));
    sort(A);
    int cnt = 0;
    rep(i, m) cnt += CountGE(A, -c[i] + x * (c[i] + d[i]));
    return cnt >= k;
  });
  wt(x * 100);
}
