#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> r(n);
  cin >> r;
  sort(r);
  double c = 0;
  rep(i, k) c = (c + r[n - k + i]) / 2;
  wt(c);
}
