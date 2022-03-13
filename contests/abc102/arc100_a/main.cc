#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  rep(i, n) a[i] -= i + 1;
  sort(a);
  int ans = 0;
  rep(i, n) ans += abs(a[i] - a[n / 2]);
  wt(ans);
}
