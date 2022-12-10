#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, t);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(a);
  t %= sum;
  int x = 0;
  rep(i, n) {
    x += a[i];
    if (x > t) {
      wt(i + 1, t - (x - a[i]));
      return;
    }
  }
}
