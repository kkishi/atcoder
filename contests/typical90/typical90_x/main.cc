#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n), b(n);
  cin >> a >> b;
  int sum = 0;
  rep(i, n) sum += abs(a[i] - b[i]);
  wt(sum <= k && even(k - sum));
}
