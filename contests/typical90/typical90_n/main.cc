#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  sort(a);
  sort(b);
  int ans = 0;
  rep(i, n) ans += abs(a[i] - b[i]);
  wt(ans);
}
