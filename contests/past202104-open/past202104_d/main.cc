#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int s = 0;
  rep(i, n) {
    if (i - k >= 0) s -= a[i - k];
    s += a[i];
    if (i >= k - 1) wt(s);
  }
}
