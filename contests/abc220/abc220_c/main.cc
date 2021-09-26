#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(x);
  int sum = accumulate(all(a), int(0));
  int ans = (x / sum) * n;
  x %= sum;
  rep(i, n) {
    x -= a[i];
    if (x < 0) {
      wt(ans + i + 1);
      return;
    }
  }
}
