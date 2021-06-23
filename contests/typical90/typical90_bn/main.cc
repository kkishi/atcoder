#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> l(n), r(n);
  rep(i, n) cin >> l[i] >> r[i];
  double ans = 0;
  rep(i, n - 1) rep(j, i + 1, n) {
    double one = 0, zero = 0;
    rep(a, l[i], r[i] + 1) rep(b, l[j], r[j] + 1)(a > b ? one : zero) += 1;
    ans += one / (one + zero);
  }
  wt(ans);
}
