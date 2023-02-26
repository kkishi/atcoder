#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n * 5);
  cin >> x;
  sort(x);
  double ans = 0;
  rep(i, 3 * n) ans += x[i + n];
  wt(ans / (3 * n));
}
