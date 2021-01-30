#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n * 3);
  cin >> a;
  sort(all(a), greater{});
  int ans = 0;
  rep(i, n) ans += a[i * 2 + 1];
  wt(ans);
}
