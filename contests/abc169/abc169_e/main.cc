#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  sort(a);
  sort(b);
  if (n % 2) {
    wt(b[n / 2] - a[n / 2] + 1);
  } else {
    int am = a[n / 2 - 1] + a[n / 2];
    int bm = b[n / 2 - 1] + b[n / 2];
    wt(bm - am + 1);
  }
}
