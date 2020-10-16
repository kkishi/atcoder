#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n - 1), b(n);
  cin >> a;
  rep(i, n - 1)++ b[a[i] - 1];
  rep(i, n) wt(b[i]);
}
