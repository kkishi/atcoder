#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  rep(i, k, n) wt(a[i] > a[i - k]);
}
