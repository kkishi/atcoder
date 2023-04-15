#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  VV<int> b(k);
  rep(i, n) b[i % k].eb(a[i]);
  V<CumulativeSum1D<int>> cs;
  rep(i, k) cs.eb(CumulativeSum1D(b[i]));
  ints(q);
  rep(q) {
    ints(l, r);
    --l;
    // Take the last k elements of [l, r).
    V<int> A(k);
    rep(i, k) A[i] = a[r - k + i];
    rep(i, k) {
      int j = r - k + i;
      // sum = a[j] + a[j-k] + ...
      int low = j - (j - l) / k * k;
      int high = i == 0 ? j : (j - k);
      int sum = low > high ? 0 : cs[j % k].Get(low / k, high / k);
      if (i == 0) {
        rep(j, k) A[j] -= sum;
        A[0] = 0;
      } else {
        A[i] += sum;
      }
    }
    wt(A == V<int>(k));
  }
}
