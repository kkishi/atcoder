#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k, x);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(a);
  int q = 0;
  rep(i, n) {
    q += a[i] / x;
    a[i] %= x;
  }
  if (q >= k) {
    wt(sum - k * x);
  } else {
    sort(a, greater{});
    wt(accumulate(a.begin() + min(n, k - q), a.end(), int(0)));
  }
}
