#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a, greater{});
  int alice = 0, bob = 0;
  rep(i, n)((i & 1) ? bob : alice) += a[i];
  wt(alice - bob);
}
