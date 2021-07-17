#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x);
  V<int> a(n);
  cin >> a;
  int sum = 0;
  rep(i, n) {
    sum += a[i];
    if (!even(i)) --sum;
  }
  wt(sum <= x);
}
