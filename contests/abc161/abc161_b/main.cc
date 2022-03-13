#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  wt(a[n - m] * 4 * m >= accumulate(a));
}
