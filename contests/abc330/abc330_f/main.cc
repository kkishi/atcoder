#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  sort(x);
  sort(y);
  int L = 1000000000;
  V<int> X(n), Y(n);
  rep(i, n) X[i] = L - x[n - 1 - i];
  rep(i, n) Y[i] = L - y[n - 1 - i];
  wt(BinarySearch<int>(L, -1, [&](int l) {
    auto calc = [&](const V<int>& v) {
      int lc = 0;
      int lsum = 0;
      int rc = n;
      int rsum = 0;
      rep(i, n) rsum += L - v[i];
      int j = 0;
      int ret = big;
      rep(i, n) {
        int h = v[i] + l;
        while (j < n && v[j] < h) {
          rsum -= L - v[j];
          --rc;
          ++j;
        }
        int lv = lc * v[i] - lsum;
        int rv = h >= L ? 0 : (rc * (L - h) - rsum);
        chmin(ret, lv + rv);
        lsum += v[i];
        ++lc;
      }
      return ret;
    };
    return min(calc(x), calc(X)) + min(calc(y), calc(Y)) <= k;
  }));
}
